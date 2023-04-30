#include "sidebar.hpp"

Sidebar::Sidebar(bool *freezeFrame) {
    this->freezeFrame = freezeFrame;

    setOrientation(Qt::Vertical);
    setMinimumSize(256, 0);

    layerSection = new QSplitter;
    filterSection = new QSplitter;
    layerSection->setMaximumSize(256, 256);
    filterSection->setMaximumSize(256, 256);

    toggleFreezeFrame = new QPushButton("Freeze Frame");
    connect(toggleFreezeFrame, &QPushButton::clicked, this, &Sidebar::handleFreezeFrame);
    layerSection->addWidget(toggleFreezeFrame);
    filterSection->addWidget(new QPushButton("TEST"));

    addWidget(layerSection);
    addWidget(filterSection);
}

#include <iostream>
void Sidebar::handleFreezeFrame() {
    *freezeFrame = !(*freezeFrame);
    if (*freezeFrame) {
        toggleFreezeFrame->setText("Unfreeze Frame");
    } else {
        toggleFreezeFrame->setText("Freeze Frame");
    }
}

