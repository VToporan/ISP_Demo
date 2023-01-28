#include "genericFilter.hpp"
#include <stdio.h>

void GenericFilterWrapper::applyFilter(cv::Mat indrame) {
    return;
}

void GenericFilterWrapper::setKernelSize(int newKernelSize) {
    this->kernelSize = newKernelSize;
}
