#include "lensFilter.hpp"
#include "opencv2/core/mat.hpp"

LensFitlerWrapper::LensFitlerWrapper() {
    setDistortionRadius(100.0);
    setDistortionAmount(0.0);
}

LensFitlerWrapper::LensFitlerWrapper(float initialAmount) {
    setDistortionRadius(100);
    setDistortionAmount(initialAmount);
}

void LensFitlerWrapper::applyFilter(cv::Mat &inframe) {
    int height = inframe.rows;
    int width = inframe.cols;
    int centerX = height / 2;
    int centerY = width / 2;
    float distortionFactor = 0;
    int deltaX = 0;
    int deltaY = 0;
    int distance = 0;
    int radius = cv::min(distortionRadius, cv::min(width / 2, height / 2));

    cv::Mat mapX = cv::Mat::zeros(height, width, CV_32FC1);
    cv::Mat mapY = cv::Mat::zeros(height, width, CV_32FC1);

    for (int x = 0; x < height; ++x) {
        deltaX = x - centerX;

        for (int y = 0; y < width; ++y) {
            deltaY = y - centerY;

            distance = deltaX * deltaX + deltaY * deltaY;
            if (distance >= (radius * radius)) {
                mapX.at<float>(x, y) = x;
                mapY.at<float>(x, y) = y;
            } else {
                distortionFactor = 1;
                if (distance > 0) {
                    distortionFactor =
                        std::pow(std::sin(M_PI * std::sqrt(distance) / radius / 2), distortionAmount);
                }

                mapX.at<float>(x, y) = distortionFactor * deltaX + centerX;
                mapY.at<float>(x, y) = distortionFactor * deltaY + centerY;
            }
        }
    }

    cv::remap(inframe, inframe, mapY, mapX, cv::INTER_LINEAR);
}

void LensFitlerWrapper::setDistortionAmount(float newAmount) { distortionAmount = newAmount; }

void LensFitlerWrapper::setDistortionRadius(int newFactor) { distortionRadius = newFactor; }

std::vector<parameterConfig> LensFitlerWrapper::allParameterConfigs() {
    std::vector<parameterConfig> configs;
    configs.push_back({"Distortion amount", (int)(distortionAmount * 100), -100, 100, 1,
                       [this](int x) { setDistortionAmount((float)x / 100); }});
    configs.push_back({"Distortion radius", distortionRadius, 0, 500, 1, [this](int x) { setDistortionRadius(x); }});
    return configs;
}

const char *LensFitlerWrapper::filterName() { return "Lens Distortion"; }
