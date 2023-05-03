#ifndef GAUSSIAN_FILTER_H
#define GAUSSIAN_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>
#include <vector>

class GaussianFitlerWrapper : public GenericFilterWrapper {
    private:
        int kernelSize;
        double sigmaX;
        double sigmaY;

    public:
        explicit GaussianFitlerWrapper();
        explicit GaussianFitlerWrapper(int initialKernelSize);
        explicit GaussianFitlerWrapper(int initialKernelSize, double initialSigma);
        explicit GaussianFitlerWrapper(int initialKernelSize, double initialSigmaX, double initialSigmaY);
        void applyFilter(cv::Mat &inframe);

        void setKernelSize(int newKernelSize);
        void setSigmaX(float newSigmaX);
        void setSigmaY(float newSigmaY);

        std::vector<parameterConfig> allParameterConfigs();
};

#endif
