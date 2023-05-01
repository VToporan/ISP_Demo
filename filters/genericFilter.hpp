#ifndef GENERIC_FILTER_H
#define GENERIC_FILTER_H

#include <functional>
#include <opencv2/core.hpp>
#include <vector>

class GenericFilterWrapper;
typedef struct _parameterConfig {
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
