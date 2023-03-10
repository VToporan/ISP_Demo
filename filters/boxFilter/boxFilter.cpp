#include "boxFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

BoxFitlerWrapper::BoxFitlerWrapper(int initialKernelSize) {
    setKernelSizeX(initialKernelSize);
    setKernelSizeY(initialKernelSize);
}

void BoxFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::boxFilter(inframe, inframe, 0,
                  cv::Size(kernelSizeX, kernelSizeY));
}

bool sizeIsValid(int kernelSize) {
    if (kernelSize <= 0) {
        return false;
    }

    if ((kernelSize % 2) == 0) {
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
