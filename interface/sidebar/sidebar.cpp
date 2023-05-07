#include "sidebar.hpp"
#include <iostream>

Sidebar::Sidebar(bool *initialFreezeFrame, std::vector<Layer *> *initialLayers) {
    freezeFrame = initialFreezeFrame;
    layers = initialLayers;
    currentLayerIndex = 0;
    filterSelectBox = new QComboBox;

    miscLayout = new QVBoxLayout;
    setupMiscLayout();

    layerSelectLayout = new QVBoxLayout;
    setupLayerLayout();

    filterSelectLayout = new QVBoxLayout;
    setupFilterSelectLayout();

    sliderLayout = new QVBoxLayout;
    setupSliderLayout();

    mainLayout = new QVBoxLayout;
    setupMainLayout();

    setLayout(mainLayout);
    setFixedWidth(256);
}

void Sidebar::setupMainLayout() {
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(5);

    mainLayout->addLayout(miscLayout);
    mainLayout->addLayout(layerSelectLayout);
    mainLayout->addLayout(filterSelectLayout);
    mainLayout->addLayout(sliderLayout);

    mainLayout->addStretch();
}

void Sidebar::setupMiscLayout() {
    QPushButton *freezeFrameButton = new QPushButton(*freezeFrame ? "Unfreeze Frame" : "Freeze frame");
    freezeFrameButton->setFixedHeight(40);
    connect(freezeFrameButton, &QPushButton::clicked, this, [=]() {
        *freezeFrame = !(*freezeFrame);
        freezeFrameButton->setText(*freezeFrame ? "Unfreeze Frame" : "Freeze frame");
    });

    miscLayout->addWidget(freezeFrameButton);
}

void Sidebar::setupLayerLayout() {
    createLayerSelectButtons();

    for (QPushButton *button : layerSelectButtons) {
        layerSelectLayout->addWidget(button);
    }
}

void Sidebar::setupFilterSelectLayout() {
    filterSelectBox = new QComboBox;
    filterSelectBox->setFixedHeight(35);
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

        destroyFilterSliders();
        setupSliderLayout();
    });

    filterSelectLayout->addWidget(filterSelectBox);
}

void Sidebar::setupSliderLayout() {
    createFilterSliders();
    for (Slider *slider : currentFilterSliders) {
        sliderLayout->addWidget(slider);
    }
}

void Sidebar::createLayerSelectButtons() {
    for (int layerIndex = 0; layerIndex < layers->size(); ++layerIndex) {
        layers->at(layerIndex)->setSelected(false);
        const char *currentFilterName = layers->at(layerIndex)->getCurrentFilter()->filterName();
        QPushButton *layerButton = new QPushButton(QString("Filter %1 - %2").arg(layerIndex).arg(currentFilterName));
        layerButton->setFixedHeight(50);
        connect(layerButton, &QPushButton::clicked, this, [=]() {
            currentLayerIndex = layerIndex;
            destroyLayerSelectButtons();
            setupLayerLayout();

            destroyFilterSliders();
            setupSliderLayout();
        });
        layerSelectButtons.push_back(layerButton);
    }
    layers->at(currentLayerIndex)->setSelected(true);
    layerSelectButtons.at(currentLayerIndex)->setDisabled(true);
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
