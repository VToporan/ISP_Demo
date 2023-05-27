#include "cannyFilter.hpp"

#include <opencv2/imgproc.hpp>
#include <stdio.h>

CannyFitlerWrapper::CannyFitlerWrapper() {
    setKernelSize(3);
    setLowTreshold(0);
    setHighTreshold(255);
}

CannyFitlerWrapper::CannyFitlerWrapper(int initialKernelSize) {
    setKernelSize(initialKernelSize);
    setLowTreshold(0);
    setHighTreshold(255);
}

CannyFitlerWrapper::CannyFitlerWrapper(int initialKernelSize, int initialLowTreshold) {
    setKernelSize(initialKernelSize);
    setLowTreshold(initialLowTreshold);
    setHighTreshold(initialLowTreshold * 3);
}

CannyFitlerWrapper::CannyFitlerWrapper(int initialKernelSize, int initialLowTreshold, int initialHighTreshold) {
    setKernelSize(initialKernelSize);
    setLowTreshold(initialLowTreshold);
    setHighTreshold(initialHighTreshold);
}

void CannyFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::Mat grayscale, gradX, gradY;
    cv::cvtColor(inframe, grayscale, cv::COLOR_BGR2GRAY);

    cv::Canny(grayscale, inframe, lowTreshold, highTreshold, kernelSize);
    cv::cvtColor(inframe, inframe, cv::COLOR_GRAY2BGR);
}

void CannyFitlerWrapper::setKernelSize(int newKernelSize) {
    if (newKernelSize < 3 || newKernelSize > 7) {
        kernelSize = 3;
        return;
    }

    if ((newKernelSize % 2) == 0) {
        kernelSize = 3;
        return;
    }

    kernelSize = newKernelSize;
}

void CannyFitlerWrapper::setLowTreshold(int newLowTreshold) { lowTreshold = newLowTreshold; }

void CannyFitlerWrapper::setHighTreshold(int newHighTreshold) { highTreshold = newHighTreshold; }

std::vector<parameterConfig> CannyFitlerWrapper::allParameterConfigs() {
    std::vector<parameterConfig> configs;
    configs.push_back({"Kernel size", "Changes the size of the Sobel Kernel applied", kernelSize, 3, 7, 2,
                       [this](int x) { setKernelSize(x); }});
    configs.push_back({"Low treshold", "Changes the threshold that determines suppressed pixels", lowTreshold, 1, 255,
                       1, [this](int x) { setLowTreshold(x); }});
    configs.push_back({"High treshold", "Changes the threshold that determines edge pixels", highTreshold, 1, 255, 1,
                       [this](int x) { setHighTreshold(x); }});
    return configs;
}

const char *CannyFitlerWrapper::filterName() { return "Canny Filter"; }
