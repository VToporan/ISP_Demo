#ifndef DILATE_FILTER_H
#define DILATE_FILTER_H

#include "genericFilter.hpp"
#include <vector>

class DilateFitlerWrapper : public GenericFilterWrapper {
    private:
        int dilateDiameter;

    public:
        explicit DilateFitlerWrapper();
        explicit DilateFitlerWrapper(int initialDiameter);
        void applyFilter(cv::Mat &inframe);

        void setDilateDiameter(int newDilateDiameter);

        std::vector<parameterConfig> allParameterConfigs();
};

#endif
