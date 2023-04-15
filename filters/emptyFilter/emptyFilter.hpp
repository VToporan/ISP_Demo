#ifndef EMPTY_FILTER_H
#define EMPTY_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class EmptyFitlerWrapper : public GenericFilterWrapper {
    public:
        explicit EmptyFitlerWrapper();
        void applyFilter(cv::Mat &inframe);
};

#endif
