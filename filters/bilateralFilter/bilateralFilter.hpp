#ifndef BILATERAL_FILTER_H
#define BILATERAL_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class BilateralFitlerWrapper : GenericFilterWrapper {
    private:
        int diameter;
        double sigmaColor;
        double sigmaSpace;

    public:
        explicit BilateralFitlerWrapper(int initialKernelSize);        
        explicit BilateralFitlerWrapper(int initialKernelSize, double initialSigma);
        explicit BilateralFitlerWrapper(int initialKernelSize, double initialSigmaColor, double initialSigmaSpace);

        void setKernelSize1D(int newKernelSizeX);
        void setKernelSize2D(int newKernelSizeX, int newKernelSizeY);

        void setSigma(int newSigma);
        void setSigmaColor(int newSigmaColor);
        void setSigmaSpace(int newSigmaSpace);

        double getSigmaColor();
        double getSigmaSpace();

        void applyFilter(cv::Mat &inframe);
};

#endif
