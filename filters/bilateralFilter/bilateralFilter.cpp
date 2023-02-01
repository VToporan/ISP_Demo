#include "bilateralFilter.hpp"
#include "genericFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

BilateralFitlerWrapper::BilateralFitlerWrapper(int initialKernelSize)
    : GenericFilterWrapper(initialKernelSize) {
    sigmaColor = 0;
    sigmaSpace = 0;
}

BilateralFitlerWrapper::BilateralFitlerWrapper(int initialKernelSize,
                                               double initialSigma)
    : GenericFilterWrapper(initialKernelSize) {
    if (initialSigma < 0) {
        this->sigmaColor = 0;
        this->sigmaSpace = 0;
        return;
    }

    this->sigmaColor = initialSigma;
    this->sigmaSpace = 0;
}

BilateralFitlerWrapper::BilateralFitlerWrapper(int initialKernelSize,
                                               double initialSigmaColor,
                                               double initialSigmaSpace)
    : GenericFilterWrapper(initialKernelSize) {
    if (initialSigmaColor < 0 || initialSigmaSpace < 0) {
        this->sigmaColor = 0;
        this->sigmaSpace = 0;
        return;
    }

    this->sigmaColor = initialSigmaColor;
    this->sigmaSpace = initialSigmaSpace;
}

void BilateralFitlerWrapper::applyFilter(cv::Mat& inframe) {
    cv::Mat outframe;
    cv::bilateralFilter(inframe, outframe, this->getKernelSize1D(),
                        this->getSigmaColor(), this->getSigmaSpace());
    inframe = outframe;
}

void BilateralFitlerWrapper::setSigma(int newSigma) {
    if (newSigma < 1) {
        this->sigmaColor = 0;
        this->sigmaSpace = 0;
        return;
    }

    this->sigmaColor = newSigma;
    this->sigmaSpace = 0;
}

void BilateralFitlerWrapper::setSigmaColor(int newSigmaColor) {
    if (newSigmaColor < 1) {
        this->sigmaColor = 0;
        return;
    }

    this->sigmaColor = newSigmaColor;
}

void BilateralFitlerWrapper::setSigmaSpace(int newSigmaSpace) {
    if (newSigmaSpace < 1) {
        this->sigmaSpace = 0;
        return;
    }

    this->sigmaSpace = newSigmaSpace;
}

double BilateralFitlerWrapper::getSigmaColor() { return this->sigmaColor; }

double BilateralFitlerWrapper::getSigmaSpace() { return this->sigmaSpace; }

void BilateralFitlerWrapper::setKernelSize2D(int newKernelSizeX,
                                             int newKernelSizeY) {
    return;
}

void BilateralFitlerWrapper::setKernelSize1D(int newKernelSize) {
    if (newKernelSize % 2) {
        newKernelSize++;
    }

    this->diameter = newKernelSize;
}

int BilateralFitlerWrapper::getKernelSize1D() { return this->diameter; }

cv::Size BilateralFitlerWrapper::getKernelSize2D() {
    return cv::Size(this->diameter, this->diameter);
}
