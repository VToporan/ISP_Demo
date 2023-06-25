#include "sobelFilter.hpp"

SobelFitlerWrapper::SobelFitlerWrapper() {
    setKernelSize(3);
    setDerivX(1);
    setDerivY(1);
    setMinValue(1);
    setDisplayDirection(false);
}
SobelFitlerWrapper::SobelFitlerWrapper(int initialKernelSize) {
    setKernelSize(initialKernelSize);
    setDerivX(1);
    setDerivY(1);
    setMinValue(1);
    setDisplayDirection(false);
}

SobelFitlerWrapper::SobelFitlerWrapper(int initialKernelSize, int initialDerivate) {
    setKernelSize(initialKernelSize);
    setDerivX(initialDerivate);
    setDerivY(initialDerivate);
    setMinValue(1);
    setDisplayDirection(false);
}

SobelFitlerWrapper::SobelFitlerWrapper(int initialKernelSize, int initialDerivateX, int initialDerivateY) {
    setKernelSize(initialKernelSize);
    setDerivX(initialDerivateX);
    setDerivY(initialDerivateY);
    setMinValue(1);
    setDisplayDirection(false);
}

void SobelFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::Mat grayscale, gradX, gradY;
    cv::cvtColor(inframe, grayscale, cv::COLOR_BGR2GRAY);

    cv::Sobel(grayscale, gradX, CV_64F, derivX, 0, kernelSize);

    cv::Sobel(grayscale, gradY, CV_64F, 0, derivY, kernelSize);

    if (!displayDirection) {
        cv::convertScaleAbs(gradX, gradX);
        cv::convertScaleAbs(gradY, gradY);
        cv::addWeighted(gradX, 0.5, gradY, 0.5, 0, inframe);
        inframe = ((inframe * (255 - 2 * minValue)) / 255) + 2 * minValue;
        cv::cvtColor(inframe, inframe, cv::COLOR_GRAY2BGR);

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
                magnitude = ((magnitude * (127 - minValue)) / 127) + minValue;

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
        kernelSize = 1;
        return;
    }

    if ((newKernelSize % 2) == 0) {
        kernelSize = 1;
        return;
    }

    kernelSize = newKernelSize;
}

void SobelFitlerWrapper::setDerivX(int newDerivX) {
    if (newDerivX < 1 || newDerivX > 3 || newDerivX >= kernelSize) {
        return;
    }
    derivX = newDerivX;
}

void SobelFitlerWrapper::setDerivY(int newDerivY) {
    if (newDerivY < 1 || newDerivY > 3 || newDerivY >= kernelSize) {
        return;
    }
    derivY = newDerivY;
}

void SobelFitlerWrapper::setMinValue(int newMinValue) {
    if (newMinValue < 0 || newMinValue > 127) {
        return;
    }

    minValue = newMinValue;
}

void SobelFitlerWrapper::setDisplayDirection(int isSet) { displayDirection = isSet; }

std::vector<parameterConfig> SobelFitlerWrapper::allParameterConfigs() {
    std::vector<parameterConfig> configs;
    configs.push_back({"Display direction", "Toggles directional component of the Sobel Filter", displayDirection, 0, 1,
                       1, [this](int x) { setDisplayDirection(x); }});
    configs.push_back({"Kernel size", "Changes the width and heigt of the Sobel Kernel", kernelSize, 3, 7, 2,
                       [this](int x) { setKernelSize(x); }});
    configs.push_back(
        {"Derivative order", "Changes the amount of times the derivative is computed", derivX, 1, 3, 1, [this](int x) {
             setDerivX(x);
             setDerivY(x);
         }});

    configs.push_back({"Minimum intensity", "Changes minimum display intensity for each pixel", minValue, 1, 127, 1,
                       [this](int x) { setMinValue(x); }});
    return configs;
}

const char *SobelFitlerWrapper::filterName() { return "Sobel Fitler"; }
