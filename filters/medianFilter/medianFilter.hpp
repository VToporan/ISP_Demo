#ifndef MEDIAN_FILTER_H
#define MEDIAN_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class MedianFitlerWrapper : GenericFilterWrapper {
    public:
        explicit MedianFitlerWrapper() : GenericFilterWrapper() {}
        void applyFilter(cv::Mat &inframe);
};

#endif
