#ifndef BOX_FILTER_H
#define BOX_FILTER_H

#include "genericFilter.hpp"
#include <opencv2//core.hpp>

class BoxFitlerWrapper : GenericFilterWrapper {
    public:
        explicit BoxFitlerWrapper(int initialKernelSize) : GenericFilterWrapper(initialKernelSize) {}
        void applyFilter(cv::Mat &inframe);
};

#endif
