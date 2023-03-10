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
        sigmaColor = 0;
        sigmaSpace = 0;
        return;
    }

    sigmaColor = initialSigma;
    sigmaSpace = 0;
}

BilateralFitlerWrapper::BilateralFitlerWrapper(int initialKernelSize, double initialSigmaColor,
                                               double initialSigmaSpace) {
    if (initialSigmaColor < 0 || initialSigmaSpace < 0) {
        sigmaColor = 0;
        sigmaSpace = 0;
        return;
    }

    sigmaColor = initialSigmaColor;
    sigmaSpace = initialSigmaSpace;
}

void BilateralFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::Mat outframe;
    cv::bilateralFilter(inframe, outframe, diameter, sigmaColor, sigmaSpace);
    inframe = outframe;
}

void BilateralFitlerWrapper::setDiameter(int newDiameter) {
    if (newDiameter < 1) {
        diameter = 1;
        return;
    }

    diameter = newDiameter;
}

void BilateralFitlerWrapper::setSigma(int newSigma) {
    if (newSigma < 1) {
        sigmaColor = 0;
        sigmaSpace = 0;
        return;
    }

    sigmaColor = newSigma;
    sigmaSpace = 0;
}

void BilateralFitlerWrapper::setSigmaColor(int newSigmaColor) {
    if (newSigmaColor < 1) {
        sigmaColor = 0;
        return;
    }

    sigmaColor = newSigmaColor;
}

void BilateralFitlerWrapper::setSigmaSpace(int newSigmaSpace) {
    if (newSigmaSpace < 1) {
        sigmaSpace = 0;
        return;
    }

    sigmaSpace = newSigmaSpace;
}
