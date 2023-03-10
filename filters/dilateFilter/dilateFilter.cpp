#include "dilateFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

DilateFitlerWrapper::DilateFitlerWrapper(int initialDiameter) {
    setDilateDiameter(initialDiameter);
}

void DilateFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(dilateDiameter, dilateDiameter));

    cv::dilate(inframe, inframe, kernel);
}

void DilateFitlerWrapper::setDilateDiameter(int newDilateDiameter) {
    if (dilateDiameter < 0) {
        dilateDiameter = 1;
        return;
    }

    dilateDiameter = newDilateDiameter;
}
