#include "dilateFilter.hpp"

DilateFitlerWrapper::DilateFitlerWrapper() { setDilateDiameter(3); }

DilateFitlerWrapper::DilateFitlerWrapper(int initialDiameter) { setDilateDiameter(initialDiameter); }

void DilateFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(dilateDiameter, dilateDiameter));

    cv::dilate(inframe, inframe, kernel);
}

void DilateFitlerWrapper::setDilateDiameter(int newDilateDiameter) {
    if (newDilateDiameter < 1) {
        dilateDiameter = 1;
        return;
    }

    dilateDiameter = newDilateDiameter;
}

std::vector<parameterConfig> DilateFitlerWrapper::allParameterConfigs() {
    std::vector<parameterConfig> configs;
    configs.push_back({"Kernel size", dilateDiameter, 3, 49, 2, [this](int x) { setDilateDiameter(x); }});
    return configs;
}

const char *DilateFitlerWrapper::filterName() { return "Dilate Filter"; }
