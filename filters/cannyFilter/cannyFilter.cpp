#include "cannyFilter.hpp"
#include "genericFilter.hpp"

#include <opencv2/imgproc.hpp>
#include <stdio.h>

CannyFitlerWrapper::CannyFitlerWrapper(int initialKernelSize)
    : GenericFilterWrapper(initialKernelSize) {
    this->setKernelSize1D(initialKernelSize);
}

CannyFitlerWrapper::CannyFitlerWrapper(int initialKernelSize,
                                       int initialLowTreshold)
    : GenericFilterWrapper(initialKernelSize) {
    this->setKernelSize1D(initialKernelSize);
    this->setLowTreshold(initialLowTreshold);
    this->setHighTreshold(initialLowTreshold * 3);
}

CannyFitlerWrapper::CannyFitlerWrapper(int initialKernelSize,
                                       int initialLowTreshold,
                                       int initialHighTreshold)
    : GenericFilterWrapper(initialKernelSize) {
    this->setKernelSize1D(initialKernelSize);
    this->setLowTreshold(initialLowTreshold);
    this->setHighTreshold(initialHighTreshold);
}

void CannyFitlerWrapper::applyFilter(cv::Mat& inframe) {
    cv::Mat grayscale, gradX, gradY;
    cv::cvtColor(inframe, grayscale, cv::COLOR_BGR2GRAY);

    cv::Canny(grayscale, inframe, getLowTreshold(), getHighTreshold(), getKernelSize1D());
}

void CannyFitlerWrapper::setKernelSize2D(int newKernelSizeX,
                                         int newKernelSizeY) {
    return;
}

void CannyFitlerWrapper::setKernelSize1D(int newKernelSize) {
    if ((newKernelSize % 2) == 0) {
        newKernelSize++;
    }

    this->kernelSize = newKernelSize;
}

int CannyFitlerWrapper::getKernelSize1D() { return this->kernelSize; }

cv::Size CannyFitlerWrapper::getKernelSize2D() {
    return cv::Size(this->kernelSize, this->kernelSize);
}

void CannyFitlerWrapper::setLowTreshold(int newLowTreshold) { this->lowTreshold = newLowTreshold; }

void CannyFitlerWrapper::setHighTreshold(int newHighTreshold) { this->highTreshold = newHighTreshold; }

int CannyFitlerWrapper::getLowTreshold() { return this->lowTreshold; }

int CannyFitlerWrapper::getHighTreshold() { return this->highTreshold; }
