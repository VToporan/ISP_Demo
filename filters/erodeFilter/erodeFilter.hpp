#ifndef ERODE_FILTER_H
#define ERODE_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class ErodeFitlerWrapper : public GenericFilterWrapper {
    private:
        int erodeDiameter;

    public:
        explicit ErodeFitlerWrapper();
        explicit ErodeFitlerWrapper(int initialDiameter);
        void applyFilter(cv::Mat &inframe);

        void setErodeDiameter(int newErodeDiameter);
};

#endif
