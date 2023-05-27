#include "sidebar.hpp"

Sidebar::Sidebar(bool *initialFreezeFrame, std::vector<Layer *> *initialLayers, QGraphicsScene *scene) {
    freezeFrame = initialFreezeFrame;
    layers = initialLayers;
    layerScene = scene;
    currentLayerIndex = 0;
    selectEnabled = new bool;
    *selectEnabled = true;

    createLayouts();
    setupAllLayouts();

    setLayout(mainLayout);
    setFixedWidth(SIDEBAR_WIDTH);
}

void Sidebar::setupAllLayouts() {
    setupMiscLayout();
    setupLayerSelectLayout();
    setupLayerManagementLayout();
    setupFilterSelectLayout();
    setupSliderLayout();
    setupMainLayout();
}

void Sidebar::setupMainLayout() {
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(5);

    mainLayout->addLayout(miscLayout);
    mainLayout->addLayout(layerManagementLayout);
    mainLayout->addLayout(layerSelectLayout);
    mainLayout->addLayout(filterSelectLayout);
    mainLayout->addLayout(sliderLayout);

    mainLayout->addStretch();
}

void Sidebar::setupMiscLayout() {
    QPushButton *toggleFreezeFrameButton = new QPushButton(*freezeFrame ? "Unfreeze Frame" : "Freeze frame");
    toggleFreezeFrameButton->setFixedHeight(MISC_BUTTON_HEIGHT);
    connect(toggleFreezeFrameButton, &QPushButton::clicked, this, [=]() {
        *freezeFrame = !(*freezeFrame);
        toggleFreezeFrameButton->setText(*freezeFrame ? "Unfreeze Frame" : "Freeze frame");
    });

    QPushButton *toggleSelectionButton = new QPushButton(*selectEnabled ? "Disable Selection" : "Enable Selection");
    toggleSelectionButton->setFixedHeight(MISC_BUTTON_HEIGHT);
    connect(toggleSelectionButton, &QPushButton::clicked, this, [=]() {
        *selectEnabled = !(*selectEnabled);
        layers->at(currentLayerIndex)->setSelected(*selectEnabled);
        toggleSelectionButton->setText(*selectEnabled ? "Disable Selection" : "Enable Selection");
    });

    miscLayout->addWidget(toggleFreezeFrameButton);
    miscLayout->addWidget(toggleSelectionButton);
}

void Sidebar::setupLayerSelectLayout() {
    destroyLayerSelectButtons();
    createLayerSelectButtons();

    for (QPushButton *button : layerSelectButtons) {
        layerSelectLayout->addWidget(button);
    }
}

void Sidebar::setupLayerManagementLayout() {
    layerManagementButtons.push_back(new QPushButton("Add"));
    layerManagementButtons.push_back(new QPushButton("Del"));
    layerManagementButtons.push_back(new QPushButton("⬆"));
    layerManagementButtons.push_back(new QPushButton("⬇"));

    connect(layerManagementButtons.at(0), &QPushButton::clicked, this, [=]() {
        if (layers->size() == MAX_LAYERS) {
            return;
        }
        layers->push_back(new Layer(0, layerScene));
        currentLayerIndex = layers->size() - 1;
        setupLayerSelectLayout();
        updateLayerManagement();
    });

    connect(layerManagementButtons.at(1), &QPushButton::clicked, this, [=]() {
        if (layers->size() <= 1) {
            return;
        }

        delete layers->at(currentLayerIndex);
        layers->erase(layers->begin() + currentLayerIndex);
        if (currentLayerIndex > 0) {
            currentLayerIndex -= 1;
        }
        setupLayerSelectLayout();
        updateLayerManagement();
    });

    connect(layerManagementButtons.at(2), &QPushButton::clicked, this, [=]() {
        if (currentLayerIndex == 0) {
            return;
        }
        std::iter_swap(layers->begin() + currentLayerIndex, layers->begin() + currentLayerIndex - 1);
        currentLayerIndex -= 1;
        setupLayerSelectLayout();
        updateLayerManagement();
    });

    connect(layerManagementButtons.at(3), &QPushButton::clicked, this, [=]() {
        if (currentLayerIndex >= layers->size() - 1) {
            return;
        }
        std::iter_swap(layers->begin() + currentLayerIndex, layers->begin() + currentLayerIndex + 1);
        currentLayerIndex += 1;
        setupLayerSelectLayout();
        updateLayerManagement();
    });

    for (QPushButton *button : layerManagementButtons) {
        button->setFixedHeight(MISC_BUTTON_HEIGHT);
        layerManagementLayout->addWidget(button);
    }
    updateLayerManagement();
}

void Sidebar::setupFilterSelectLayout() {
    filterSelectBox = new QComboBox;
    filterSelectBox->setFixedHeight(FILTER_SELECT_HEIGHT);
    std::vector<GenericFilterWrapper *> filters = layers->at(currentLayerIndex)->getFilters();

    for (int i = 0; i < filters.size(); ++i) {
        filterSelectBox->insertItem(i, QString(filters[i]->filterName()));
    }

    connect(filterSelectBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int x) {
        layers->at(currentLayerIndex)->setIndex(x);
        layerSelectButtons.at(currentLayerIndex)
            ->setText(QString("Filter %1 - %2")
                          .arg(currentLayerIndex)
                          .arg(layers->at(currentLayerIndex)->getCurrentFilter()->filterName()));

        setupSliderLayout();
    });

    QPushButton *infoButton = new QPushButton("i");
    infoButton->setFixedSize(FILTER_SELECT_HEIGHT, FILTER_SELECT_HEIGHT);

    connect(infoButton, &QPushButton::pressed, this,
            [=]() { QToolTip::showText(infoButton->mapToGlobal(QPoint()), infoText, infoButton); });

    filterSelectLayout->addWidget(filterSelectBox);
    filterSelectLayout->addWidget(infoButton);
}

void Sidebar::setupSliderLayout() {
    destroyFilterSliders();
    createFilterSliders();
    for (Slider *slider : currentFilterSliders) {
        sliderLayout->addWidget(slider);
    }
    createInfoText();
}

void Sidebar::createLayouts() {
    filterSelectBox = new QComboBox;
    miscLayout = new QHBoxLayout;
    layerSelectLayout = new QVBoxLayout;
    layerManagementLayout = new QHBoxLayout;
    filterSelectLayout = new QHBoxLayout;
    sliderLayout = new QVBoxLayout;
    mainLayout = new QVBoxLayout;
}

void Sidebar::createLayerSelectButtons() {
    for (int layerIndex = 0; layerIndex < layers->size(); ++layerIndex) {
        layers->at(layerIndex)->setSelected(false);
        const char *currentFilterName = layers->at(layerIndex)->getCurrentFilter()->filterName();
        QPushButton *layerButton = new QPushButton(QString("Filter %1 - %2").arg(layerIndex).arg(currentFilterName));
        layerButton->setFixedHeight(LAYER_BUTTON_HEIGHT);
        connect(layerButton, &QPushButton::clicked, this, [=]() {
            currentLayerIndex = layerIndex;
            setupLayerSelectLayout();
            setupSliderLayout();
            updateLayerManagement();
        });
        layerSelectButtons.push_back(layerButton);
    }
    layers->at(currentLayerIndex)->setSelected(true);
    layerSelectButtons.at(currentLayerIndex)->setDisabled(true);
    layerSelectButtons.at(currentLayerIndex)->setPalette(QColor(CURRENT_LAYER_COLOR));
    filterSelectBox->setCurrentIndex(layers->at(currentLayerIndex)->getIndex());
}

void Sidebar::destroyLayerSelectButtons() {
    for (QPushButton *layerButton : layerSelectButtons) {
        delete layerButton;
    }
    layerSelectButtons.clear();
}

void Sidebar::createFilterSliders() {
    for (parameterConfig config : layers->at(currentLayerIndex)->getCurrentFilter()->allParameterConfigs()) {
        currentFilterSliders.push_back(new Slider(config));
    }
}

void Sidebar::destroyFilterSliders() {
    for (Slider *slider : currentFilterSliders) {
        delete slider;
    }
    currentFilterSliders.clear();
}

void Sidebar::updateLayerManagement() {
    for (QPushButton *button : layerManagementButtons) {
        button->setDisabled(false);
    }

    layerManagementButtons.at(3)->setDisabled(currentLayerIndex >= layers->size() - 1);
    layerManagementButtons.at(2)->setDisabled(currentLayerIndex <= 0);
    layerManagementButtons.at(1)->setDisabled(layers->size() <= 1);
    layerManagementButtons.at(0)->setDisabled(layers->size() >= MAX_LAYERS);
}

void Sidebar::createInfoText() {
    infoText = "";
    infoText.append("<b>Info</b><br>");

    GenericFilterWrapper *currentFilter = layers->at(currentLayerIndex)->getCurrentFilter();
    infoText.append(currentFilter->filterName());
    infoText.append("<br><br>");

    std::vector<parameterConfig> configs = currentFilter->allParameterConfigs();
    for (parameterConfig config : configs) {
        infoText.append("<b>");
        infoText.append(config.name);
        infoText.append("</b> - ");
        infoText.append(config.description);
        infoText.append("<br>");
    }
}
