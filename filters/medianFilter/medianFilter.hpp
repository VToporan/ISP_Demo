#ifndef MEDIAN_FILTER_H
#define MEDIAN_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class MedianFitlerWrapper : GenericFilterWrapper {
  private:
    int kernelSize;

  public:
    explicit MedianFitlerWrapper(int initialKernelSize)
        : GenericFilterWrapper(initialKernelSize) {}
    void setKernelSize2D(int newKernelSizeX, int newKernelSizeY);
    void setKernelSize1D(int newKernelSize);
    void applyFilter(cv::Mat& inframe);
};

#endif
