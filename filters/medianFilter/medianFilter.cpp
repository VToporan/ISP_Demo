#include "medianFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

MedianFitlerWrapper::MedianFitlerWrapper() { setKernelSize(3); }

MedianFitlerWrapper::MedianFitlerWrapper(int initialKernelSize) { setKernelSize(initialKernelSize); }

void MedianFitlerWrapper::applyFilter(cv::Mat &inframe) { cv::medianBlur(inframe, inframe, kernelSize); }

void MedianFitlerWrapper::setKernelSize(int newKernelSize) {
    if ((newKernelSize % 2) == 0) {
        newKernelSize++;
    }

    kernelSize = newKernelSize;
}
