#ifndef GAUSSIAN_FILTER_H
#define GAUSSIAN_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class GaussianFitlerWrapper : public GenericFilterWrapper {
    private:
        int kernelSize;
        double sigmaX;
        double sigmaY;

    public:
        explicit GaussianFitlerWrapper(int initialKernelSize);
        explicit GaussianFitlerWrapper(int initialKernelSize,
                                       double initialSigma);
        explicit GaussianFitlerWrapper(int initialKernelSize,
                                       double initialSigmaX,
                                       double initialSigmaY);
        void setSigma(int newSigma);
        void setSigmaX(int newSigmaX);
        void setSigmaY(int newSigmaY);
        void applyFilter(cv::Mat &inframe);
};

#endif
