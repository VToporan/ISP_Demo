#ifndef GENERIC_FILTER_H
#define GENERIC_FILTER_H

#include <opencv2/core.hpp>

class GenericFilterWrapper {
    private:
        cv::Size kernelSize;

    public:
        explicit GenericFilterWrapper();
        virtual void applyFilter(cv::Mat indrame);
        virtual void setKernelSize(cv::Size newKernelSize);
        virtual cv::Size getKernelSize();
};

#endif
