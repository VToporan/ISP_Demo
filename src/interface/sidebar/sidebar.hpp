#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "style.hpp"
#include "layer/layer.hpp"
#include "slider/slider.hpp"
#include "button/button.hpp"

#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QToolTip>

#include <vector>
#include <algorithm>
#include <iostream>

class Sidebar : public QWidget {
    public:
        Sidebar(bool *freezeFrame, std::vector<Layer *> *layers, QGraphicsScene *scene);

    private:
        bool *freezeFrame;
        bool *selectEnabled;
        int currentLayerIndex;
        std::vector<Layer *> *layers;
        std::vector<Slider *> currentFilterSliders;
        std::vector<QPushButton *> layerSelectButtons;
        std::vector<QPushButton *> layerManagementButtons;

        QFont miscButtonFont;
        QFont layerButtonFont;
        QFont selectButtonFont;
        QString infoText;
        QComboBox *filterSelectBox;
        QVBoxLayout *mainLayout;
        QHBoxLayout *miscLayout;
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
        void createInfoText();
};

#endif
