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

void GaussianFitlerWrapper::setSigmaX(float newSigmaX) {
    if (newSigmaX < 0) {
        sigmaX = 0;
        return;
    }

    sigmaX = newSigmaX;
}

void GaussianFitlerWrapper::setSigmaY(float newSigmaY) {
    if (newSigmaY < 0) {
        sigmaY = 0;
        return;
    }

    sigmaY = newSigmaY;
}

std::vector<parameterConfig> GaussianFitlerWrapper::allParameterConfigs() {
    std::vector<parameterConfig> configs;
    configs.push_back({"Kernel size", kernelSize, 3, 79, 2, [this](int x) { setKernelSize(x); }});
    configs.push_back(
        {"Sigma value on X axis", (int)(sigmaX * 10), 1, 101, 1, [this](int x) { setSigmaX((float)x / 10); }});
    configs.push_back(
        {"Sigma value on Y axis", (int)(sigmaY * 10), 1, 101, 1, [this](int x) { setSigmaY((float)x / 10); }});
    return configs;
}

const char *GaussianFitlerWrapper::filterName() { return "Gaussian Filter"; }
