#include "cannyFilter.hpp"
#include "genericFilter.hpp"

#include <opencv2/imgproc.hpp>
#include <stdio.h>

CannyFitlerWrapper::CannyFitlerWrapper(int initialKernelSize) { this->setKernelSize(initialKernelSize); }

CannyFitlerWrapper::CannyFitlerWrapper(int initialKernelSize, int initialLowTreshold) {
    this->setKernelSize(initialKernelSize);
    this->setLowTreshold(initialLowTreshold);
    this->setHighTreshold(initialLowTreshold * 3);
}

CannyFitlerWrapper::CannyFitlerWrapper(int initialKernelSize, int initialLowTreshold, int initialHighTreshold) {
    this->setKernelSize(initialKernelSize);
    this->setLowTreshold(initialLowTreshold);
    this->setHighTreshold(initialHighTreshold);
}

void CannyFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::Mat grayscale, gradX, gradY;
    cv::cvtColor(inframe, grayscale, cv::COLOR_BGR2GRAY);

    cv::Canny(grayscale, inframe, this->lowTreshold, this->highTreshold, this->kernelSize);
}

void CannyFitlerWrapper::setKernelSize(int newKernelSize) {
    if (newKernelSize < 0) {
        this->kernelSize = 1;
        return;
    }

    if ((newKernelSize % 2) == 0) {
        this->kernelSize = 1;
        return;
    }

    this->kernelSize = newKernelSize;
}

void CannyFitlerWrapper::setLowTreshold(int newLowTreshold) { this->lowTreshold = newLowTreshold; }

void CannyFitlerWrapper::setHighTreshold(int newHighTreshold) { this->highTreshold = newHighTreshold; }
