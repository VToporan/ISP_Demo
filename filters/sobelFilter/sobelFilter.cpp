#include "sobelFilter.hpp"
#include "genericFilter.hpp"
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
    cv::Mat grayscale;
    cvtColor(inframe, grayscale, cv::COLOR_BGR2GRAY);

    printf("Sobel kermel %d \n", this->getKernelSize1D());
    cv::Sobel(grayscale, inframe, 0, this->getDerivX(), this->getDerivY(),
              this->getKernelSize1D());
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
