#include "sidebar.hpp"
#include "qobjectdefs.h"

Sidebar::Sidebar(bool *initialFreezeFrame, std::vector<Layer *> *initialLayers) {
    freezeFrame = initialFreezeFrame;
    layers = initialLayers;
    combo = new QComboBox(this);
    selectLayer(layers->front());

    setOrientation(Qt::Vertical);
    setMinimumSize(256, 0);

    layerSection = new QSplitter;
    layerSection->setFixedSize(256, 226);
    layerSection->setOrientation(Qt::Vertical);

    filterSection = new QSplitter;
    filterSection->setFixedSize(256, 286);
    filterSection->setOrientation(Qt::Vertical);

    freezeFrameButton = new QPushButton("Freeze Frame");
    connect(freezeFrameButton, &QPushButton::clicked, this, &Sidebar::toggleFreezeFrame);
    layerSection->addWidget(freezeFrameButton);

    for (int i = 0; i < layers->size(); ++i) {
        QPushButton *newButton = new QPushButton(QString("Layer %1").arg(i));
        connect(newButton, &QPushButton::clicked, this, [=]() { selectLayer((*layers)[i]); });
        layerSection->addWidget(newButton);
    }

    for (int i = 0; i < 10; ++i) {
        combo->insertItem(i, QString("Filter %1").arg(i));
    }
    combo->setFixedHeight(25);
    connect(combo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int x) {
        currentLayer->setIndex(x);
        selectLayer(currentLayer);
    });
    layerSection->addWidget(combo);

    addWidget(layerSection);
    addWidget(filterSection);
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
        filterSection->addWidget(slider);
    }

    currentLayer = selectedLayer;
    combo->setCurrentIndex(currentLayer->getIndex());
}
