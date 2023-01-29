#include "medianFilter.hpp"
#include "opencv2/imgproc.hpp"
#include <stdio.h>

void MedianFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::medianBlur(inframe, inframe, 5);
}
