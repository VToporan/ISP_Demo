#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "layer/layer.hpp"
#include "slider/slider.hpp"

#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>

#include <vector>

class Sidebar : public QWidget {
        Q_OBJECT;

    public:
        Sidebar(bool *freezeFrame, std::vector<Layer *> *layers);

    private:
        bool *freezeFrame;
        int currentLayerIndex;
        std::vector<Layer *> *layers;
        std::vector<Slider *> currentFilterSliders;
        std::vector<QPushButton *> layerSelectButtons;

        QComboBox *filterSelectBox;
        QVBoxLayout *mainLayout;
        QVBoxLayout *miscLayout;
        QVBoxLayout *layerSelectLayout;
        QVBoxLayout *filterSelectLayout;
        QVBoxLayout *sliderLayout;

        void setupMainLayout();
        void setupMiscLayout();
        void setupLayerLayout();
        void setupSliderLayout();
        void setupFilterSelectLayout();

        void createLayerSelectButtons();
        void destroyLayerSelectButtons();
        void createFilterSliders();
        void destroyFilterSliders();
};

#endif
