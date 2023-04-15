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
        explicit BilateralFitlerWrapper();
        explicit BilateralFitlerWrapper(int initialDiameter);
        explicit BilateralFitlerWrapper(int initialDiameter, double initialSigma);
        explicit BilateralFitlerWrapper(int initialDiameter, double initialSigmaColor, double initialSigmaSpace);
        void applyFilter(cv::Mat &inframe);

        void setDiameter(int newDiameter);
        void setSigmaColor(int newSigmaColor);
        void setSigmaSpace(int newSigmaSpace);
};

#endif
