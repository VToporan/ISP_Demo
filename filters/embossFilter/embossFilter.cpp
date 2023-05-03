#include "embossFilter.hpp"

EmbossFitlerWrapper::EmbossFitlerWrapper() {
    cv::Mat embossMatrix = (cv::Mat_<int8_t>(3, 3) << 1, 1, 0, 1, 0, -1, 0, -1, -1);

    for (int i = 0; i < EMBOSS_DIRECTION_TOTAL; ++i) {
        embossKernels[(EmbossDirection)i] = embossMatrix.clone();
        cv::rotate(embossMatrix, embossMatrix, cv::ROTATE_90_COUNTERCLOCKWISE);
    }

    currentDirection = EMBOSS_DIRECTION_LEFT;
}

EmbossFitlerWrapper::EmbossFitlerWrapper(EmbossDirection initialDirection) : EmbossFitlerWrapper() {
    currentDirection = initialDirection;
}

void EmbossFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::Mat grayscale;
    cv::cvtColor(inframe, grayscale, cv::COLOR_BGR2GRAY);

    cv::filter2D(grayscale, inframe, -1, embossKernels[currentDirection]);

    inframe += 127;
    cv::cvtColor(inframe, inframe, cv::COLOR_GRAY2BGR);
}

void EmbossFitlerWrapper::setEmbossDirection(EmbossDirection newDirection) { currentDirection = newDirection; }

std::vector<parameterConfig> EmbossFitlerWrapper::allParameterConfigs() {
    std::vector<parameterConfig> configs;
    configs.push_back({"Emboss direction", (int)currentDirection, 0, 3, 1, [this](int x) { setEmbossDirection((EmbossDirection)x); }});
    return configs;
}
