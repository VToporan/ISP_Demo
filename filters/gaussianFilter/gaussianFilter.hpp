#ifndef GAUSSIAN_FILTER_H
#define GAUSSIAN_FILTER_H

#include "genericFilter.hpp"
#include <opencv2//core.hpp>

class GaussianFitlerWrapper : GenericFilterWrapper {
    public:
        explicit GaussianFitlerWrapper(int initialKernelSize) : GenericFilterWrapper(initialKernelSize) {}
        void applyFilter(cv::Mat &inframe);
};

#endif
