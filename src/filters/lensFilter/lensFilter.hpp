#ifndef LENS_FILTER_H
#define LENS_FILTER_H

#include "genericFilter.hpp"

class LensFitlerWrapper : public GenericFilterWrapper {
    private:
        float distortionAmount;
        int distortionRadius;

    public:
        explicit LensFitlerWrapper();
        explicit LensFitlerWrapper(float initialAmount);
        void applyFilter(cv::Mat &inframe);

        void setDistortionAmount(float newAmount);
        void setDistortionRadius(int newRadius);

        std::vector<parameterConfig> allParameterConfigs();
        const char* filterName();
};

#endif
