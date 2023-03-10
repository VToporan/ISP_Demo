#ifndef GENERIC_FILTER_H
#define GENERIC_FILTER_H

#include <opencv2/core.hpp>

class GenericFilterWrapper {
    public:
        virtual void applyFilter(cv::Mat &inframe) = 0;
};

#endif
