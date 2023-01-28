#include "genericFilter.hpp"
#include <stdio.h>

GenericFilterWrapper::GenericFilterWrapper() {
    this->kernelSize = cv::Size(30, 30); 
}

void GenericFilterWrapper::applyFilter(cv::Mat indrame) {
    return;
}

void GenericFilterWrapper::setKernelSize(cv::Size newKernelSize) {
    this->kernelSize = newKernelSize;
}

cv::Size GenericFilterWrapper::getKernelSize() {
    return this->kernelSize;
}
