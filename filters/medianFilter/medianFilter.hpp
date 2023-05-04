#ifndef MEDIAN_FILTER_H
#define MEDIAN_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class MedianFitlerWrapper : virtual public GenericFilterWrapper {
    private:
        int kernelSize;

    public:
        explicit MedianFitlerWrapper();
        explicit MedianFitlerWrapper(int initialKernelSize);
        void setKernelSize(int newKernelSize);
        void applyFilter(cv::Mat &inframe);

        std::vector<parameterConfig> allParameterConfigs();
        const char* filterName();
};

#endif
