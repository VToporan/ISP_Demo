#ifndef SOBEL_FILTER_H
#define SOBEL_FILTER_H

#include "genericFilter.hpp"

class SobelFitlerWrapper : public GenericFilterWrapper {
    private:
        int kernelSize;
        int derivX;
        int derivY;
        bool displayDirection;

    public:
        explicit SobelFitlerWrapper();
        explicit SobelFitlerWrapper(int initialKernelSize);
        explicit SobelFitlerWrapper(int initialKernelSize, int initialDerivate);
        explicit SobelFitlerWrapper(int initialKernelSize, int initialDerivateX, int initialDerivateY);
        void applyFilter(cv::Mat &inframe);

        void setKernelSize(int newKernelSize);
        void setDerivX(int newDerivX);
        void setDerivY(int newDerivY);
        void setDisplayDirection(int isSet);

        std::vector<parameterConfig> allParameterConfigs();
        const char* filterName();
};

#endif
