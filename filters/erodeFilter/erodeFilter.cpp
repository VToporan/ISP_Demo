#include "erodeFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

ErodeFitlerWrapper::ErodeFitlerWrapper(int initialDiameter) { setErodeDiameter(initialDiameter); }

void ErodeFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(erodeDiameter, erodeDiameter));

    cv::erode(inframe, inframe, kernel);
}

void ErodeFitlerWrapper::setErodeDiameter(int newErodeDiameter) {
    if (erodeDiameter < 0) {
        erodeDiameter = 1;
        return;
    }

    erodeDiameter = newErodeDiameter;
}
