#ifndef LENS_FILTER_H
#define LENS_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class LensFitlerWrapper : public GenericFilterWrapper {
    private:
        float distortionAmount;

    public:
        explicit LensFitlerWrapper();
        explicit LensFitlerWrapper(float initialAmount);

        void applyFilter(cv::Mat &inframe);

        void setdistortionAmount(int newAmount);
};

#endif
