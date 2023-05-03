#include "bilateralFilter.hpp"

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
    if (newSigmaColor < 0) {
        sigmaColor = 0;
        return;
    }

    sigmaColor = newSigmaColor;
}

void BilateralFitlerWrapper::setSigmaSpace(int newSigmaSpace) {
    if (newSigmaSpace < 0) {
        sigmaSpace = 0;
        return;
    }

    sigmaSpace = newSigmaSpace;
}

std::vector<parameterConfig> BilateralFitlerWrapper::allParameterConfigs() {
    std::vector<parameterConfig> configs;
    configs.push_back({"Kernel size", diameter, 1, 11, 2, [this](int x) { setDiameter(x); }});
    configs.push_back(
        {"Sigma color value", (int)sigmaColor * 1, 1, 101, 1, [this](int x) { setSigmaColor((float)x / 1); }});
    configs.push_back(
        {"Sigma space value", (int)sigmaSpace * 1, 1, 101, 1, [this](int x) { setSigmaSpace((float)x / 1); }});
    return configs;
}
