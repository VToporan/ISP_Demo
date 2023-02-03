#ifndef ERODE_FILTER_H
#define ERODE_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class ErodeFitlerWrapper : public GenericFilterWrapper {
  public:
    explicit ErodeFitlerWrapper(int initialKernelSize)
        : GenericFilterWrapper(initialKernelSize) {}
    void applyFilter(cv::Mat& inframe);
};

#endif
