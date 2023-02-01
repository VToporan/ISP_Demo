#include "boxFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

void BoxFitlerWrapper::applyFilter(cv::Mat& inframe) {
    cv::boxFilter(inframe, inframe, 0, getKernelSize2D());
}
