#include "sobelFilter.hpp"
#include "genericFilter.hpp"
#include "opencv2/core.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

SobelFitlerWrapper::SobelFitlerWrapper(int initialKernelSize)
    : GenericFilterWrapper(initialKernelSize) {
    this->setKernelSize1D(initialKernelSize);
}

SobelFitlerWrapper::SobelFitlerWrapper(int initialKernelSize,
                                       int initialDerivate)
    : GenericFilterWrapper(initialKernelSize) {
    this->setKernelSize1D(initialKernelSize);
    this->setDerivX(initialDerivate);
    this->setDerivY(initialDerivate);
}

SobelFitlerWrapper::SobelFitlerWrapper(int initialKernelSize,
                                       int initialDerivateX,
                                       int initialDerivateY)
    : GenericFilterWrapper(initialKernelSize) {
    this->setKernelSize1D(initialKernelSize);
    this->setDerivX(initialDerivateX);
    this->setDerivY(initialDerivateY);
}

void SobelFitlerWrapper::applyFilter(cv::Mat& inframe) {
    cv::Mat grayscale, gradX, gradY;
    cvtColor(inframe, grayscale, cv::COLOR_BGR2GRAY);

    cv::Sobel(grayscale, gradX, 0, this->getDerivX(), 0,
              this->getKernelSize1D());
    
    cv::Sobel(grayscale, gradY, 0, 0, this->getDerivY(),
              this->getKernelSize1D());

    cv::convertScaleAbs(gradX, gradX);
    cv::convertScaleAbs(gradY, gradY);

    cv::addWeighted(gradX, 0.5, gradY, 0.5, 0, inframe);
}

void SobelFitlerWrapper::setKernelSize2D(int newKernelSizeX,
                                         int newKernelSizeY) {
    return;
}

void SobelFitlerWrapper::setKernelSize1D(int newKernelSize) {
    if ((newKernelSize % 2) == 0) {
        newKernelSize++;
    }

    printf("Sobel kermel %d \n", newKernelSize);

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
