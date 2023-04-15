#include "bilateralFilter.hpp"

#include <opencv2/imgproc.hpp>
#include <stdio.h>

BilateralFitlerWrapper::BilateralFitlerWrapper() {
    setDiameter(3);
    setSigmaColor(0);
    setSigmaSpace(0);
}

BilateralFitlerWrapper::BilateralFitlerWrapper(int initialDiameter) {
    setDiameter(initialDiameter);
    setSigmaColor(0);
    setSigmaSpace(0);
}

BilateralFitlerWrapper::BilateralFitlerWrapper(int initialDiameter, double initialSigma) {
    setDiameter(initialDiameter);
    setSigmaColor(initialSigma);
    setSigmaSpace(initialSigma);
}

BilateralFitlerWrapper::BilateralFitlerWrapper(int initialDiameter, double initialSigmaColor,
                                               double initialSigmaSpace) {
    setDiameter(initialDiameter);
    setSigmaColor(initialSigmaColor);
    setSigmaSpace(initialSigmaSpace);
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
