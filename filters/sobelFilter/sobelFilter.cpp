#include "sobelFilter.hpp"
#include "genericFilter.hpp"
#include "opencv2/core.hpp"
#include "opencv2/core/matx.hpp"
#include "opencv2/imgproc.hpp"
#include <cmath>
#include <iostream>
#include <stdio.h>

SobelFitlerWrapper::SobelFitlerWrapper(int initialKernelSize)
    : GenericFilterWrapper(initialKernelSize) {
    this->setKernelSize1D(initialKernelSize);
    this->displayDirection = false;
}

SobelFitlerWrapper::SobelFitlerWrapper(int initialKernelSize,
                                       int initialDerivate)
    : GenericFilterWrapper(initialKernelSize) {
    this->setKernelSize1D(initialKernelSize);
    this->setDerivX(initialDerivate);
    this->setDerivY(initialDerivate);
    this->displayDirection = false;
}

SobelFitlerWrapper::SobelFitlerWrapper(int initialKernelSize,
                                       int initialDerivateX,
                                       int initialDerivateY)
    : GenericFilterWrapper(initialKernelSize) {
    this->setKernelSize1D(initialKernelSize);
    this->setDerivX(initialDerivateX);
    this->setDerivY(initialDerivateY);
    this->displayDirection = false;
}

void SobelFitlerWrapper::applyFilter(cv::Mat& inframe) {
    cv::Mat grayscale, gradX, gradY;
    cv::cvtColor(inframe, grayscale, cv::COLOR_BGR2GRAY);

    cv::Sobel(grayscale, gradX, CV_64F, this->getDerivX(), 0,
              this->getKernelSize1D());

    cv::Sobel(grayscale, gradY, CV_64F, 0, this->getDerivY(),
              this->getKernelSize1D());

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

void SobelFitlerWrapper::setKernelSize2D(int newKernelSizeX,
                                         int newKernelSizeY) {
    return;
}

void SobelFitlerWrapper::setKernelSize1D(int newKernelSize) {
    if ((newKernelSize % 2) == 0) {
        newKernelSize++;
    }

    this->kernelSize = newKernelSize;
}

int SobelFitlerWrapper::getKernelSize1D() { return this->kernelSize; }

cv::Size SobelFitlerWrapper::getKernelSize2D() {
    return cv::Size(this->kernelSize, this->kernelSize);
}

void SobelFitlerWrapper::setDerivX(int newDerivX) { this->derivX = newDerivX; }

void SobelFitlerWrapper::setDerivY(int newDerivY) { this->derivY = newDerivY; }

int SobelFitlerWrapper::getDerivX() { return this->derivX; }

int SobelFitlerWrapper::getDerivY() { return this->derivY; }

void SobelFitlerWrapper::toggleDisplayDirection() {
    this->displayDirection = !this->displayDirection;
}
