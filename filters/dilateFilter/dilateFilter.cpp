#include "dilateFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

DilateFitlerWrapper::DilateFitlerWrapper(int initialDiameter) {
    this->setDilateDiameter(initialDiameter);
}

void DilateFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(this->dilateDiameter, this->dilateDiameter));

    cv::dilate(inframe, inframe, kernel);
}

void DilateFitlerWrapper::setDilateDiameter(int newDilateDiameter) {
    if (dilateDiameter < 0) {
        this->dilateDiameter = 1;
        return;
    }

    this->dilateDiameter = newDilateDiameter;
}
