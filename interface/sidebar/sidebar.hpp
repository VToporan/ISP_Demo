#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "layer/layer.hpp"

#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>

#include <vector>

class Sidebar : public QWidget {
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
        QPushButton *freezeFrameButton;
        QComboBox *combo;
        QVBoxLayout *layout;

        void setupFreezeFrame();
        void setupLayerButtons();
        void setupFilterDropDown();
        void setupLayout();
};

#endif
