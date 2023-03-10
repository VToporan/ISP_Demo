#ifndef BOX_FILTER_H
#define BOX_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class BoxFitlerWrapper : public GenericFilterWrapper {
    private:
        int kernelSizeX;
        int kernelSizeY;

    public:
        explicit BoxFitlerWrapper(int initialKernelSize);
        void applyFilter(cv::Mat &inframe);

        void setKernelSizeX(int newKernelSize);
        void setKernelSizeY(int newKernelSize);
};

#endif
