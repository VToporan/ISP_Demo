#include "dilateFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

void DilateFitlerWrapper::applyFilter(cv::Mat& inframe) {
    cv::Mat kernel =
        cv::getStructuringElement(cv::MORPH_RECT, this->getKernelSize2D());

    cv::dilate(inframe, inframe, kernel);
}
