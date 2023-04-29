#include "lensFilter.hpp"
#include "genericFilter.hpp"
#include "opencv2/core/hal/interface.h"
#include "opencv2/imgproc.hpp"
#include <cmath>
#include <iostream>

LensFitlerWrapper::LensFitlerWrapper() { distortionAmount = 0.9; }

LensFitlerWrapper::LensFitlerWrapper(float initialAmount) { distortionAmount = initialAmount; }

void LensFitlerWrapper::applyFilter(cv::Mat &inframe) {
    int height = inframe.rows;
    int width = inframe.cols;
    int centerX = height / 2;
    int centerY = width / 2;
    int distortionRadius = width / 2;
    float distortionFactor = 0;
    int deltaX = 0;
    int deltaY = 0;
    int distance = 0;

    cv::Mat mapX = cv::Mat::zeros(height, width, CV_32FC1);
    cv::Mat mapY = cv::Mat::zeros(height, width, CV_32FC1);

    for (int x = 0; x < height; ++x) {
        deltaX = x - centerX;

        for (int y = 0; y < width; ++y) {
            deltaY = y - centerY;

            distance = deltaX * deltaX + deltaY * deltaY;
            if (distance >= (distortionRadius * distortionRadius)) {
                mapX.at<float>(x, y) = x;
                mapY.at<float>(x, y) = y;
            } else {
                distortionFactor = 1;
                if (distance > 0) {
                    distortionFactor =
                        std::pow(std::sin(M_PI * std::sqrt(distance) / distortionRadius / 2), distortionAmount);
                }

                mapX.at<float>(x, y) = distortionFactor * deltaX + centerX;
                mapY.at<float>(x, y) = distortionFactor * deltaY + centerY;
            }
        }
    }

    cv::remap(inframe, inframe, mapY, mapX, cv::INTER_LINEAR);
}
