#include "cannyFilter.hpp"
#include "genericFilter.hpp"

#include <opencv2/imgproc.hpp>
#include <stdio.h>

CannyFitlerWrapper::CannyFitlerWrapper(int initialKernelSize) { setKernelSize(initialKernelSize); }

CannyFitlerWrapper::CannyFitlerWrapper(int initialKernelSize, int initialLowTreshold) {
    setKernelSize(initialKernelSize);
    setLowTreshold(initialLowTreshold);
    setHighTreshold(initialLowTreshold * 3);
}

CannyFitlerWrapper::CannyFitlerWrapper(int initialKernelSize, int initialLowTreshold, int initialHighTreshold) {
    setKernelSize(initialKernelSize);
    setLowTreshold(initialLowTreshold);
    setHighTreshold(initialHighTreshold);
}

void CannyFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::Mat grayscale, gradX, gradY;
    cv::cvtColor(inframe, grayscale, cv::COLOR_BGR2GRAY);

    cv::Canny(grayscale, inframe, lowTreshold, highTreshold, kernelSize);
}

void CannyFitlerWrapper::setKernelSize(int newKernelSize) {
    if (newKernelSize < 0) {
        kernelSize = 1;
        return;
    }

    if ((newKernelSize % 2) == 0) {
        kernelSize = 1;
        return;
    }

    kernelSize = newKernelSize;
}

void CannyFitlerWrapper::setLowTreshold(int newLowTreshold) { lowTreshold = newLowTreshold; }

void CannyFitlerWrapper::setHighTreshold(int newHighTreshold) { highTreshold = newHighTreshold; }
