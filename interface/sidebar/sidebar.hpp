#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "layer/layer.hpp"

#include <QComboBox>
#include <QPushButton>
#include <QSlider>
#include <QSplitter>

#include <vector>

class Sidebar : public QSplitter {
        Q_OBJECT;

    public:
        Sidebar(bool *freezeFrame, std::vector<Layer *> *layers);

    public slots:
        void toggleFreezeFrame();
        void selectLayer(Layer *layer);

    private:
        bool *freezeFrame;
        std::vector<Layer *> *layers;
        Layer *currentLayer;
        QSplitter *layerSection;
        QSplitter *filterSection;
        QPushButton *freezeFrameButton;
        QComboBox *combo;
};

#endif
