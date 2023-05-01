#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "layer/layer.hpp"
#include "slider/slider.hpp"

#include <QPushButton>
#include <QSplitter>
#include <QSlider>

#include <vector>

class Sidebar : public QSplitter {
        Q_OBJECT;

    public:
        Sidebar(bool *freezeFrame, std::vector<Layer *> *layers);

    public slots:
        void handleFreezeFrame();
        void handleLayerSelect(Layer *layer);

    private:
        bool *freezeFrame;
        std::vector<Layer *> *layers;
        QSplitter *layerSection;
        QSplitter *filterSection;
        QPushButton *toggleFreezeFrame;
};

#endif
