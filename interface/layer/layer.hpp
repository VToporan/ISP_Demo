#ifndef LAYER_H
#define LAYER_H

#include "genericFilter.hpp"
#include "roi/roi.hpp"
#include "slider/slider.hpp"

#include <QGraphicsScene>
#include <opencv2/opencv.hpp>
#include <vector>

class Layer {
    public:
        Layer(int initialIndex, QGraphicsScene *scene);
        ~Layer();
        void setupFilters();
        void applyFilter(cv::Mat &inframe);
        void setSelected(bool isSelected);
        void setIndex(int newIndex);
        int getIndex();
        std::vector<Slider *> getSliders();

    private:
        std::vector<GenericFilterWrapper *> allFilters;
        std::vector<Slider *> sliders;
        GenericFilterWrapper *currentFilter;
        Roi *roi;
        int currentIndex;

        void setSliders();
        void clearSliders();
};

#endif
