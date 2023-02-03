#include "medianFilter.hpp"
#include "genericFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

MedianFitlerWrapper::MedianFitlerWrapper(int initialKernelSize)
    : GenericFilterWrapper(initialKernelSize) {
    this->setKernelSize1D(initialKernelSize);
}

void MedianFitlerWrapper::applyFilter(cv::Mat& inframe) {
    cv::medianBlur(inframe, inframe, this->getKernelSize1D());
}

void MedianFitlerWrapper::setKernelSize2D(int newKernelSizeX,
                                          int newKernelSizeY) {
    return;
}

void MedianFitlerWrapper::setKernelSize1D(int newKernelSize) {
    if ((newKernelSize % 2) == 0) {
        newKernelSize++;
    }

    this->kernelSize = newKernelSize;
}

int MedianFitlerWrapper::getKernelSize1D() { return this->kernelSize; }

cv::Size MedianFitlerWrapper::getKernelSize2D() {
    return cv::Size(this->kernelSize, this->kernelSize);
}
