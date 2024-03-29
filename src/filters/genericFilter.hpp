#ifndef GENERIC_FILTER_H
#define GENERIC_FILTER_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#include <functional>
#include <vector>

typedef struct _parameterConfig {
    const char* name;
    const char* description;
    int currentValue;
    int minValue;
    int maxValue;
    int step;
    std::function<void(int)>setter;
} parameterConfig;

class GenericFilterWrapper {
    public:
        virtual void applyFilter(cv::Mat &inframe) = 0;
        virtual std::vector<parameterConfig> allParameterConfigs() = 0;
        virtual const char *filterName() = 0;
};

#endif
