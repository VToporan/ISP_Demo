#include "erodeFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

void ErodeFitlerWrapper::applyFilter(cv::Mat& inframe) {
    cv::Mat kernel =
        cv::getStructuringElement(cv::MORPH_RECT, this->getKernelSize2D());

    cv::erode(inframe, inframe, kernel);
}
