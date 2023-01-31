#include "genericFilter.hpp"
#include <opencv2/core.hpp>
#include <stdio.h>

GenericFilterWrapper::GenericFilterWrapper(int initialKernelSize) {
    setKernelSize1D(initialKernelSize);
}

void GenericFilterWrapper::applyFilter(cv::Mat indrame) { return; }

void GenericFilterWrapper::setKernelSize2D(int newKernelSizeX,
                                           int newKernelSizeY) {
    if (newKernelSizeX < 1 || newKernelSizeY < 1) {
        this->kernelSizeX = 1;
        this->kernelSizeY = 1;
        return;
    }

    this->kernelSizeX = newKernelSizeX;
    this->kernelSizeY = newKernelSizeY;
}

void GenericFilterWrapper::setKernelSize1D(int newKernelSize) {
    if (newKernelSize < 1) {
        this->kernelSizeX = 1;
        this->kernelSizeY = 1;
        return;
    }

    this->kernelSizeX = newKernelSize;
    this->kernelSizeY = newKernelSize;
}

cv::Size GenericFilterWrapper::getKernelSize() {
    return cv::Size(this->kernelSizeX, this->kernelSizeY);
}
