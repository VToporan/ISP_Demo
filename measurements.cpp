#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgcodecs.hpp>

#include "bilateralFilter/bilateralFilter.hpp"
#include "boxFilter/boxFilter.hpp"
#include "cannyFilter/cannyFilter.hpp"
#include "dilateFilter/dilateFilter.hpp"
#include "embossFilter/embossFilter.hpp"
#include "emptyFilter/emptyFilter.hpp"
#include "erodeFilter/erodeFilter.hpp"
#include "gaussianFilter/gaussianFilter.hpp"
#include "genericFilter.hpp"
#include "lensFilter/lensFilter.hpp"
#include "medianFilter/medianFilter.hpp"
#include "sobelFilter/sobelFilter.hpp"

std::ofstream csv;

void createFilters(std::vector<GenericFilterWrapper *> &allFilters) {
    allFilters.push_back(new EmptyFitlerWrapper());
    allFilters.push_back(new BoxFitlerWrapper());
    allFilters.push_back(new MedianFitlerWrapper());
    allFilters.push_back(new GaussianFitlerWrapper());
    allFilters.push_back(new BilateralFitlerWrapper());
    allFilters.push_back(new DilateFitlerWrapper());
    allFilters.push_back(new ErodeFitlerWrapper());
    allFilters.push_back(new SobelFitlerWrapper());
    allFilters.push_back(new CannyFitlerWrapper());
    allFilters.push_back(new EmbossFitlerWrapper());
    allFilters.push_back(new LensFitlerWrapper());
}

void resetConfig(parameterConfig *config) {
    config->currentValue = config->minValue;
    config->setter(config->currentValue);
}

void updateConfig(parameterConfig *config) {
    int steps = (config->maxValue - config->minValue);
    steps += steps % 2;
    steps /= 2 * config->step;
    int newValue = config->currentValue + steps * config->step;

    config->currentValue = newValue;
    config->setter(newValue);
}

void resetFilters(std::vector<GenericFilterWrapper *> &allFilters) {
    for (GenericFilterWrapper *filterWrapper : allFilters) {
        std::vector<parameterConfig> configs = filterWrapper->allParameterConfigs();
        for (parameterConfig config : configs) {
            resetConfig(&config);
        }
    }
}

std::vector<uint64> cache = std::vector<uint64>();
void micro_benchmark_clear_cache() {
    cache.resize(32 * 1000 * 1000);
    for (size_t i = 0; i < cache.size(); i++) {
        cache[i] += 1;
    }
}

void computeTime(GenericFilterWrapper *filterWrapper, cv::Mat image) {
    micro_benchmark_clear_cache();
    int64 t1 = cv::getTickCount();

    filterWrapper->applyFilter(image);

    int64 t2 = cv::getTickCount();

    csv << (double)((t2 - t1) * 1000) / cv::getTickFrequency() << "\n";
}

void getCombinations(std::vector<parameterConfig> configs, int currentIndex, int values[],
                     GenericFilterWrapper *filterWrapper, cv::Mat image) {
    if (currentIndex >= configs.size()) {
        for (int i = 0; i < configs.size(); ++i) {
            csv << values[i] << ", ";
        }
        computeTime(filterWrapper, image);
        return;
    }
    parameterConfig currentConfig = configs[currentIndex];
    resetConfig(&currentConfig);

    while (currentConfig.currentValue <= currentConfig.maxValue) {
        values[currentIndex] = currentConfig.currentValue;
        getCombinations(configs, currentIndex + 1, values, filterWrapper, image);
        updateConfig(&currentConfig);
    }
}

void printHeader(std::vector<parameterConfig> configs) {
    for (parameterConfig config : configs) {
        csv << config.name << ", ";
    }
    csv << "Compute time\n";
}

void setup(std::vector<GenericFilterWrapper *> &allFilters, cv::Mat &originalImage) {
    csv << std::fixed;
    csv << std::setprecision(5);

    createFilters(allFilters);
    resetFilters(allFilters);

    originalImage = cv::imread("../resources/800x800.jpeg", cv::IMREAD_COLOR);
    csv.open("../resources/measurements.csv");
}

void taredown(std::vector<GenericFilterWrapper *> allFilters) { allFilters.clear(); }

int main(int argc, char *argv[]) {
    std::vector<GenericFilterWrapper *> allFilters;
    cv::Mat originalImage, cloneImage;

    setup(allFilters, originalImage);
    for (GenericFilterWrapper *filterWrapper : allFilters) {
        csv << filterWrapper->filterName() << "\n";
        std::vector<parameterConfig> configs = filterWrapper->allParameterConfigs();
        cloneImage = originalImage.clone();
        int values[4] = {0};

        printHeader(configs);
        getCombinations(configs, 0, values, filterWrapper, cloneImage);
        csv << "\n";
    }

    taredown(allFilters);

    return 0;
}
