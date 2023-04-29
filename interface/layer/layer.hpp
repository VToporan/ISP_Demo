#ifndef LAYER_H
#define LAYER_H

#include "genericFilter.hpp"
#include "roi/roi.hpp"

#include <QGraphicsScene>
#include <opencv2/opencv.hpp>
#include <vector>

class Layer {
    public:
        Layer(int initialIndex, QGraphicsScene *scene);
        ~Layer();
        void setupFilters();
        void applyFilter(cv::Mat &inframe);

    private:
        std::vector<GenericFilterWrapper *> allFilters;
        GenericFilterWrapper *currentFilter;
        Roi *roi;
        int currentIndex;
};

#endif
