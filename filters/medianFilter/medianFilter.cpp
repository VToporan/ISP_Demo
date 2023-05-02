#include "medianFilter.hpp"

MedianFitlerWrapper::MedianFitlerWrapper() { setKernelSize(1); }

MedianFitlerWrapper::MedianFitlerWrapper(int initialKernelSize) { setKernelSize(initialKernelSize); }

void MedianFitlerWrapper::applyFilter(cv::Mat &inframe) { cv::medianBlur(inframe, inframe, kernelSize); }

void MedianFitlerWrapper::setKernelSize(int newKernelSize) {
    if ((newKernelSize % 2) == 0) {
        return;
    }

    kernelSize = newKernelSize;
}

std::vector<parameterConfig> MedianFitlerWrapper::allParameterConfigs() {
    std::vector<parameterConfig> configs;
    configs.push_back({"Kernel size", kernelSize, 1, 49, 2, [this](int x) { setKernelSize(x); }});
    return configs;
}
