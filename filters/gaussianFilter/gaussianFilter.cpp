#include "gaussianFilter.hpp"
#include "genericFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <stdio.h>

GaussianFitlerWrapper::GaussianFitlerWrapper(int initialKernelSize) {
    kernelSize = initialKernelSize;
    sigmaX = 0;
    sigmaY = 0;
}

GaussianFitlerWrapper::GaussianFitlerWrapper(int initialKernelSize,
                                             double initialSigma) {
    if (initialSigma < 0) {
        sigmaX = 0;
        sigmaY = 0;
        return;
    }

    sigmaX = initialSigma;
    sigmaY = initialSigma;
}

GaussianFitlerWrapper::GaussianFitlerWrapper(int initialKernelSize,
                                             double initialSigmaX,
                                             double initialSigmaY) {
    if (initialSigmaX < 0 || initialSigmaY < 0) {
        sigmaX = 0;
        sigmaY = 0;
        return;
    }

    sigmaX = initialSigmaX;
    sigmaY = initialSigmaY;
}

void GaussianFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::GaussianBlur(inframe, inframe,
                     cv::Size(kernelSize, kernelSize), sigmaX,
                     sigmaY);
}

void GaussianFitlerWrapper::setSigma(int newSigma) {
    if (newSigma < 1) {
        sigmaX = 0;
        sigmaY = 0;
        return;
    }

    sigmaX = newSigma;
    sigmaY = 0;
}

void GaussianFitlerWrapper::setSigmaX(int newSigmaX) {
    if (newSigmaX < 1) {
        sigmaX = 0;
        return;
    }

    sigmaX = newSigmaX;
}

void GaussianFitlerWrapper::setSigmaY(int newSigmaY) {
    if (newSigmaY < 1) {
        sigmaY = 0;
        return;
    }

    sigmaY = newSigmaY;
}
