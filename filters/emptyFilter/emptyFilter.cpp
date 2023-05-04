#include "emptyFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

EmptyFitlerWrapper::EmptyFitlerWrapper() {
    return;
}

void EmptyFitlerWrapper::applyFilter(cv::Mat &inframe) {
    return;
}

std::vector<parameterConfig> EmptyFitlerWrapper::allParameterConfigs() {
    std::vector<parameterConfig> configs;
    return configs;
}

const char *EmptyFitlerWrapper::filterName() { return "No filter"; }
