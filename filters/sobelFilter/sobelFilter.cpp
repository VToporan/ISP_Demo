#include "sobelFilter.hpp"
#include "genericFilter.hpp"
#include "opencv2/core.hpp"
#include "opencv2/core/matx.hpp"
#include "opencv2/imgproc.hpp"
#include <cmath>
#include <iostream>
#include <stdio.h>

SobelFitlerWrapper::SobelFitlerWrapper(int initialKernelSize) {
    setKernelSize(initialKernelSize);
    this->displayDirection = false;
}

SobelFitlerWrapper::SobelFitlerWrapper(int initialKernelSize, int initialDerivate) {
    setKernelSize(initialKernelSize);
    this->setDerivX(initialDerivate);
    this->setDerivY(initialDerivate);
    this->displayDirection = false;
}

SobelFitlerWrapper::SobelFitlerWrapper(int initialKernelSize, int initialDerivateX, int initialDerivateY) {
    setKernelSize(initialKernelSize);
    this->setDerivX(initialDerivateX);
    this->setDerivY(initialDerivateY);
    this->displayDirection = false;
}

void SobelFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::Mat grayscale, gradX, gradY;
    cv::cvtColor(inframe, grayscale, cv::COLOR_BGR2GRAY);

    cv::Sobel(grayscale, gradX, CV_64F, this->derivX, 0, this->kernelSize);

    cv::Sobel(grayscale, gradY, CV_64F, 0, this->derivY, this->kernelSize);

    if (!this->displayDirection) {
        cv::convertScaleAbs(gradX, gradX);
        cv::convertScaleAbs(gradY, gradY);
        cv::addWeighted(gradX, 0.5, gradY, 0.5, 0, inframe);

    } else {
        cv::Vec3b channels;
        double theta;
        double magnitude;
        double elementX;
        double elementY;

        for (int i = 0; i < inframe.rows; ++i) {
            for (int j = 0; j < inframe.cols; ++j) {
                elementX = gradX.at<double>(i, j);
                elementY = gradY.at<double>(i, j);
                theta = std::atan2(elementX, elementY);
                magnitude = std::sqrt((elementX * elementX) + (elementY * elementY));

                channels[2] = magnitude * (1 - std::cos(theta));
                channels[1] = magnitude * (1 - std::cos(theta + (M_PI * 2) / 3));
                channels[0] = magnitude * (1 - std::cos(theta - (M_PI * 2) / 3));

                inframe.at<cv::Vec3b>(i, j) = channels;
            }
        }
    }
}

void SobelFitlerWrapper::setKernelSize(int newKernelSize) {
    if (newKernelSize < 0) {
        this->kernelSize = 1;
        return;
    }

    if ((newKernelSize % 2) == 0) {
        this->kernelSize = 1;
        return;
    }

    this->kernelSize = newKernelSize;
}

void SobelFitlerWrapper::setDerivX(int newDerivX) { this->derivX = newDerivX; }

void SobelFitlerWrapper::setDerivY(int newDerivY) { this->derivY = newDerivY; }

void SobelFitlerWrapper::toggleDisplayDirection() { this->displayDirection = !this->displayDirection; }
