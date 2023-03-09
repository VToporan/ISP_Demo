#ifndef BILATERAL_FILTER_H
#define BILATERAL_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class BilateralFitlerWrapper : public GenericFilterWrapper {
    private:
        int diameter;
        double sigmaColor;
        double sigmaSpace;

    public:
        explicit BilateralFitlerWrapper(int initialKernelSize);
        explicit BilateralFitlerWrapper(int initialKernelSize, double initialSigma);
        explicit BilateralFitlerWrapper(int initialKernelSize, double initialSigmaColor, double initialSigmaSpace);
        void applyFilter(cv::Mat &inframe);

        void setDiameter(int newDiameter);
        void setSigma(int newSigma);
        void setSigmaColor(int newSigmaColor);
        void setSigmaSpace(int newSigmaSpace);

        void setKernelSizeX(int newKernelSize);
        void setKernelSizeY(int newKernelSize);
};

#endif
