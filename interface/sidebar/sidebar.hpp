#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "layer/layer.hpp"

#include <QPushButton>
#include <QSplitter>

#include <vector>

class Sidebar : public QSplitter {
        Q_OBJECT;

    public:
        Sidebar(bool *freezeFrame);

    public slots:
        void handleFreezeFrame();

    private:
        bool *freezeFrame;
        std::vector<Layer *> *layers;
        QSplitter *layerSection;
        QSplitter *filterSection;
        QPushButton *toggleFreezeFrame;
};

#endif
