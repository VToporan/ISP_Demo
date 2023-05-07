#include "erodeFilter.hpp"

ErodeFitlerWrapper::ErodeFitlerWrapper() { setErodeDiameter(3); }

ErodeFitlerWrapper::ErodeFitlerWrapper(int initialDiameter) { setErodeDiameter(initialDiameter); }

void ErodeFitlerWrapper::applyFilter(cv::Mat &inframe) {
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(erodeDiameter, erodeDiameter));

    cv::erode(inframe, inframe, kernel);
}

void ErodeFitlerWrapper::setErodeDiameter(int newErodeDiameter) {
    if (newErodeDiameter < 1) {
        erodeDiameter = 1;
        return;
    }

    erodeDiameter = newErodeDiameter;
}

std::vector<parameterConfig> ErodeFitlerWrapper::allParameterConfigs() {
    std::vector<parameterConfig> configs;
    configs.push_back({"Kernel size", erodeDiameter, 1, 49, 2, [this](int x) { setErodeDiameter(x); }});
    return configs;
}

const char *ErodeFitlerWrapper::filterName() { return "Erode Filter"; }
