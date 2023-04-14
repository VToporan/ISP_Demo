#ifndef LAYER_H
#define LAYER_H

#include "genericFilter.hpp"

#include <opencv2/opencv.hpp>
#include <vector>

class Layer {
    public:
        Layer();
        ~Layer();
        void applyFilter(cv::Mat &inframe);

    private:
        std::vector<GenericFilterWrapper *> allFilters;
        GenericFilterWrapper *currentFilter;
};

#endif
