#ifndef CANNY_FILTER_H
#define CANNY_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class CannyFitlerWrapper : public GenericFilterWrapper {
    private:
        int kernelSize;
        int lowTreshold;
        int highTreshold;

    public:
        explicit CannyFitlerWrapper(int initialKernelSize);
        explicit CannyFitlerWrapper(int initialKernelSize, int initialTreshold);
        explicit CannyFitlerWrapper(int initialKernelSize, int initialLowTreshold, int initialHighTreshold);
        void applyFilter(cv::Mat &inframe);

        void setKernelSize(int newKernelSize);
        void setLowTreshold(int newLowTreshold);
        void setHighTreshold(int newHighTreshold);
};

#endif
