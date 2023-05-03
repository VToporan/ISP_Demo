#include "sidebar.hpp"

Sidebar::Sidebar(bool *initialFreezeFrame, std::vector<Layer *> *initialLayers) {
    freezeFrame = initialFreezeFrame;
    layers = initialLayers;

    setOrientation(Qt::Vertical);
    setMinimumSize(256, 0);

    layerSection = new QSplitter;
    layerSection->setFixedSize(256, 226);
    layerSection->setOrientation(Qt::Vertical);

    filterSection = new QSplitter;
    filterSection->setFixedSize(256, 286);
    filterSection->setOrientation(Qt::Vertical);

    toggleFreezeFrame = new QPushButton("Freeze Frame");
    connect(toggleFreezeFrame, &QPushButton::clicked, this, &Sidebar::handleFreezeFrame);
    layerSection->addWidget(toggleFreezeFrame);

    for (int i = 0; i < layers->size(); ++i) {
        QPushButton *newButton = new QPushButton(QString("Layer %1").arg(i));
        connect(newButton, &QPushButton::clicked, this, [=]() { handleLayerSelect((*layers)[i]); });
        layerSection->addWidget(newButton);
    }

    addWidget(layerSection);
    addWidget(filterSection);
}

void Sidebar::handleFreezeFrame() {
    *freezeFrame = !(*freezeFrame);
    if (*freezeFrame) {
        toggleFreezeFrame->setText("Unfreeze Frame");
    } else {
        toggleFreezeFrame->setText("Freeze Frame");
    }
}

void Sidebar::handleLayerSelect(Layer *selectedLayer) {
    for (Layer *layer : *layers) {
        layer->setSelected(false);
    }

    selectedLayer->setSelected(true);
    for (Slider *slider : selectedLayer->getSliders()) {
        filterSection->addWidget(slider);
    }
}
