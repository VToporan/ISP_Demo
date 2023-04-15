#ifndef DILATE_FILTER_H
#define DILATE_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class DilateFitlerWrapper : public GenericFilterWrapper {
    private:
        int dilateDiameter;

    public:
        explicit DilateFitlerWrapper();
        explicit DilateFitlerWrapper(int initialDiameter);
        void applyFilter(cv::Mat &inframe);

        void setDilateDiameter(int newDilateDiameter);
};

#endif
