#include "gaussianFilter.hpp"
#include "genericFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

GaussianFitlerWrapper::GaussianFitlerWrapper(int initialKernelSize) {
    this->kernelSize = initialKernelSize;
    this->sigmaX = 0;
    this->sigmaY = 0;
}

GaussianFitlerWrapper::GaussianFitlerWrapper(int initialKernelSize,
                                             double initialSigma) {
    if (initialSigma < 0) {
        this->sigmaX = 0;
        this->sigmaY = 0;
        return;
    }

    this->sigmaX = initialSigma;
    this->sigmaY = initialSigma;
}

GaussianFitlerWrapper::GaussianFitlerWrapper(int initialKernelSize,
                                             double initialSigmaX,
                                             double initialSigmaY) {
    if (initialSigmaX < 0 || initialSigmaY < 0) {
        this->sigmaX = 0;
        this->sigmaY = 0;
        return;
    }

    this->sigmaX = initialSigmaX;
    this->sigmaY = initialSigmaY;
}

void GaussianFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::GaussianBlur(inframe, inframe,
                     cv::Size(this->kernelSize, this->kernelSize), this->sigmaX,
                     this->sigmaY);
}

void GaussianFitlerWrapper::setSigma(int newSigma) {
    if (newSigma < 1) {
        this->sigmaX = 0;
        this->sigmaY = 0;
        return;
    }

    this->sigmaX = newSigma;
    this->sigmaY = 0;
}

void GaussianFitlerWrapper::setSigmaX(int newSigmaX) {
    if (newSigmaX < 1) {
        this->sigmaX = 0;
        return;
    }

    this->sigmaX = newSigmaX;
}

void GaussianFitlerWrapper::setSigmaY(int newSigmaY) {
    if (newSigmaY < 1) {
        this->sigmaY = 0;
        return;
    }

    this->sigmaY = newSigmaY;
}
