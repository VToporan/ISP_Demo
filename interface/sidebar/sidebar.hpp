#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "layer/layer.hpp"
#include "slider/slider.hpp"

#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsScene>

#include <vector>
#include <algorithm>
#include <iostream>

#define MAX_LAYERS (3)

class Sidebar : public QWidget {
    public:
        Sidebar(bool *freezeFrame, std::vector<Layer *> *layers, QGraphicsScene *scene);

    private:
        bool *freezeFrame;
        int currentLayerIndex;
        std::vector<Layer *> *layers;
        std::vector<Slider *> currentFilterSliders;
        std::vector<QPushButton *> layerSelectButtons;
        std::vector<QPushButton *> layerManagementButtons;

        QComboBox *filterSelectBox;
        QVBoxLayout *mainLayout;
        QVBoxLayout *miscLayout;
        QVBoxLayout *layerSelectLayout;
        QHBoxLayout *layerManagementLayout;
        QHBoxLayout *filterSelectLayout;
        QVBoxLayout *sliderLayout;
        QGraphicsScene *layerScene;

        void setupAllLayouts();
        void setupMainLayout();
        void setupMiscLayout();
        void setupLayerSelectLayout();
        void setupLayerManagementLayout();
        void setupSliderLayout();
        void setupFilterSelectLayout();

        void createLayouts();
        void createLayerSelectButtons();
        void destroyLayerSelectButtons();
        void createFilterSliders();
        void destroyFilterSliders();
        void updateLayerManagement();
};

#endif
