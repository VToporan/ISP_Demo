#include "sidebar.hpp"
#include "qobjectdefs.h"

#include <QSplitter>
Sidebar::Sidebar(bool *initialFreezeFrame, std::vector<Layer *> *initialLayers) {
    freezeFrame = initialFreezeFrame;
    layers = initialLayers;
    currentLayer = layers->front();

    setFixedWidth(256);
    layout = new QVBoxLayout(this);
    setLayout(layout);

    setupFreezeFrame();
    layout->addWidget(freezeFrameButton, 0, Qt::AlignTop);

    for (int i = 0; i < layers->size(); ++i) {
        QPushButton *newButton = new QPushButton(QString("Layer %1").arg(i));
        newButton->setFixedHeight(60);
        connect(newButton, &QPushButton::clicked, this, [=]() { selectLayer((*layers)[i]); });
        layout->addWidget(newButton, 0, Qt::AlignTop);
    }

    setupFilterDropDown();
    layout->addWidget(combo, 0, Qt::AlignTop);

    setupLayout();
    layout->addStretch();
    selectLayer(currentLayer);
}

void Sidebar::toggleFreezeFrame() {
    *freezeFrame = !(*freezeFrame);
    if (*freezeFrame) {
        freezeFrameButton->setText("Unfreeze Frame");
    } else {
        freezeFrameButton->setText("Freeze Frame");
    }
}

void Sidebar::selectLayer(Layer *selectedLayer) {
    for (Layer *layer : *layers) {
        layer->setSelected(false);
    }

    selectedLayer->setSelected(true);
    for (Slider *slider : selectedLayer->getSliders()) {
        layout->insertWidget(layout->count()- 1, slider);
    }

    currentLayer = selectedLayer;
    combo->setCurrentIndex(currentLayer->getIndex());
}

void Sidebar::setupFreezeFrame() {
    freezeFrameButton = new QPushButton("Freeze Frame");
    freezeFrameButton->setFixedHeight(40);
    connect(freezeFrameButton, &QPushButton::clicked, this, &Sidebar::toggleFreezeFrame);
}

void Sidebar::setupFilterDropDown() {
    combo = new QComboBox(this);
    combo->setFixedHeight(35);
    std::vector<GenericFilterWrapper *> filters = currentLayer->getFilters();
    for (int i = 0; i < filters.size(); ++i) {
        combo->insertItem(i, QString(filters[i]->filterName()));
    }
    connect(combo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int x) {
        currentLayer->setIndex(x);
        selectLayer(currentLayer);
    });
}

void Sidebar::setupLayout() {
    layout->setSpacing(5);
    layout->setMargin(5);
}
