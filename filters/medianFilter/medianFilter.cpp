#include "medianFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

void MedianFitlerWrapper::applyFilter(cv::Mat& inframe) {
    cv::medianBlur(inframe, inframe, this->getKernelSize().height);
}

void MedianFitlerWrapper::setKernelSize2D(int newKernelSizeX,
                                          int newKernelSizeY) {
    return;
}

void MedianFitlerWrapper::setKernelSize1D(int newKernelSize) {
    if (newKernelSize % 2) {
        newKernelSize++;
    }

    this->kernelSize = newKernelSize;
}
