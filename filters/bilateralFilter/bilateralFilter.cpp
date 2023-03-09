#include "bilateralFilter.hpp"
#include "genericFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

BilateralFitlerWrapper::BilateralFitlerWrapper(int initialKernelSize) {
    sigmaColor = 0;
    sigmaSpace = 0;
}

BilateralFitlerWrapper::BilateralFitlerWrapper(int initialKernelSize, double initialSigma) {
    if (initialSigma < 0) {
        this->sigmaColor = 0;
        this->sigmaSpace = 0;
        return;
    }

    this->sigmaColor = initialSigma;
    this->sigmaSpace = 0;
}

BilateralFitlerWrapper::BilateralFitlerWrapper(int initialKernelSize, double initialSigmaColor,
                                               double initialSigmaSpace) {
    if (initialSigmaColor < 0 || initialSigmaSpace < 0) {
        this->sigmaColor = 0;
        this->sigmaSpace = 0;
        return;
    }

    this->sigmaColor = initialSigmaColor;
    this->sigmaSpace = initialSigmaSpace;
}

void BilateralFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::Mat outframe;
    cv::bilateralFilter(inframe, outframe, this->diameter, this->sigmaColor, this->sigmaSpace);
    inframe = outframe;
}

void BilateralFitlerWrapper::setDiameter(int newDiameter) {
    if (newDiameter < 1) {
        this->diameter = 1;
        return;
    }

    this->diameter = newDiameter;
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
