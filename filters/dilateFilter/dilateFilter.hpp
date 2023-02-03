#ifndef DILATE_FILTER_H
#define DILATE_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class DilateFitlerWrapper : public GenericFilterWrapper {
  public:
    explicit DilateFitlerWrapper(int initialKernelSize)
        : GenericFilterWrapper(initialKernelSize) {}
    void applyFilter(cv::Mat& inframe);
};

#endif
