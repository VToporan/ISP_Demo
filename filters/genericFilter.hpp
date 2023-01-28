#ifndef GENERIC_FILTER_H
#define GENERIC_FILTER_H

#include <opencv2/core.hpp>

class GenericFilterWrapper {
    private:
        int kernelSize;

    public:
        virtual void applyFilter(cv::Mat indrame);
        virtual void setKernelSize(int newKernelSize);
};

#endif
