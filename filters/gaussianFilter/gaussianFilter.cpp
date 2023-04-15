#include "gaussianFilter.hpp"
#include "genericFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

GaussianFitlerWrapper::GaussianFitlerWrapper() {
    setKernelSize(3);
    setSigmaX(5);
    setSigmaY(5);
}

GaussianFitlerWrapper::GaussianFitlerWrapper(int initialKernelSize) {
    setKernelSize(initialKernelSize);
    setSigmaX(5);
    setSigmaY(5);
}

GaussianFitlerWrapper::GaussianFitlerWrapper(int initialKernelSize, double initialSigma) {
    setKernelSize(initialKernelSize);
    setSigmaX(initialSigma);
    setSigmaY(initialSigma);
}

GaussianFitlerWrapper::GaussianFitlerWrapper(int initialKernelSize, double initialSigmaX, double initialSigmaY) {
    setKernelSize(initialKernelSize);
    setSigmaX(initialSigmaX);
    setSigmaY(initialSigmaY);
}

void GaussianFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::GaussianBlur(inframe, inframe, cv::Size(kernelSize, kernelSize), sigmaX, sigmaY);
}

void GaussianFitlerWrapper::setKernelSize(int newKernelSize) {
    if (newKernelSize < 1) {
        kernelSize = 3;
        return;
    } 

    if (newKernelSize % 2 == 0) {
        kernelSize = 3;
        return;
    }

    kernelSize = newKernelSize;
}

void GaussianFitlerWrapper::setSigmaX(int newSigmaX) {
    if (newSigmaX < 1) {
        sigmaX = 0;
        return;
    }

    sigmaX = newSigmaX;
}

void GaussianFitlerWrapper::setSigmaY(int newSigmaY) {
    if (newSigmaY < 1) {
        sigmaY = 0;
        return;
    }

    sigmaY = newSigmaY;
}
