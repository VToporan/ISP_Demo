#include "boxFilter.hpp"

BoxFitlerWrapper::BoxFitlerWrapper() {
    setKernelSizeX(3);
    setKernelSizeY(3);
}

BoxFitlerWrapper::BoxFitlerWrapper(int initialKernelSize) {
    setKernelSizeX(initialKernelSize);
    setKernelSizeY(initialKernelSize);
}

void BoxFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::boxFilter(inframe, inframe, 0, cv::Size(kernelSizeX, kernelSizeY));
}

bool sizeIsValid(int kernelSize) {
    if (kernelSize <= 0) {
        return false;
    }

    return true;
}

void BoxFitlerWrapper::setKernelSizeX(int newKernelSize) {
    if (sizeIsValid(newKernelSize)) {
        kernelSizeX = newKernelSize;
    }
}

void BoxFitlerWrapper::setKernelSizeY(int newKernelSize) {
    if (sizeIsValid(newKernelSize)) {
        kernelSizeY = newKernelSize;
    }
}

std::vector<parameterConfig> BoxFitlerWrapper::allParameterConfigs() {
    std::vector<parameterConfig> configs;
    configs.push_back({"Kernel size X axis", kernelSizeX, 1, 79, 2, [this](int x) { setKernelSizeX(x); }});
    configs.push_back({"Kernel size Y axis", kernelSizeY, 1, 79, 2, [this](int x) { setKernelSizeY(x); }});
    return configs;
}
