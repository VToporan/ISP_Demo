#include "medianFilter.hpp"
#include "genericFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

MedianFitlerWrapper::MedianFitlerWrapper(int initialKernelSize) {
  setKernelSize1D(initialKernelSize);
}

void MedianFitlerWrapper::applyFilter(cv::Mat &inframe) {
  cv::medianBlur(inframe, inframe, kernelSize);
}

void MedianFitlerWrapper::setKernelSize2D(int newKernelSizeX,
                                          int newKernelSizeY) {
  return;
}

void MedianFitlerWrapper::setKernelSize1D(int newKernelSize) {
  if ((newKernelSize % 2) == 0) {
    newKernelSize++;
  }

  kernelSize = newKernelSize;
}
