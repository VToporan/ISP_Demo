#ifndef LAYER_H
#define LAYER_H

#include "genericFilter.hpp"

#include <opencv2/opencv.hpp>
#include <QGraphicsRectItem>
#include <vector>

class Layer {
    public:
        Layer(int initialIndex, QGraphicsRectItem *rect);
        ~Layer();
        void setupFilters();
        void applyFilter(cv::Mat &inframe);

    private:
        std::vector<GenericFilterWrapper *> allFilters;
        GenericFilterWrapper *currentFilter;
        QGraphicsRectItem *rect;
        int currentIndex;
};

#endif
