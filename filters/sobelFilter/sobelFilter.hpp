#ifndef SOBEL_FILTER_H
#define SOBEL_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class SobelFitlerWrapper : public GenericFilterWrapper {
    private:
        int kernelSize;
        int derivX;
        int derivY;
        bool displayDirection;

    public:
        explicit SobelFitlerWrapper(int initialKernelSize);
        explicit SobelFitlerWrapper(int initialKernelSize, int initialDerivate);
        explicit SobelFitlerWrapper(int initialKernelSize, int initialDerivateX, int initialDerivateY);
        void applyFilter(cv::Mat &inframe);

        void setKernelSize(int newKernelSize);
        void setDerivX(int newDerivX);
        void setDerivY(int newDerivY);
        void toggleDisplayDirection();
};

#endif
