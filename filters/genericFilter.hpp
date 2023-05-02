#ifndef GENERIC_FILTER_H
#define GENERIC_FILTER_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <functional>
#include <vector>

class GenericFilterWrapper;
typedef struct _parameterConfig {
    const char* name;
    int currentValue;
    int minValue;
    int maxValue;
    int step;
    std::function<void(int)>setter;
} parameterConfig;

class GenericFilterWrapper {
    public:
        virtual void applyFilter(cv::Mat &inframe) = 0;
        virtual std::vector<parameterConfig> allParameterConfigs() {
            std::vector<parameterConfig> configs;
            return configs;
        }
};

#endif
