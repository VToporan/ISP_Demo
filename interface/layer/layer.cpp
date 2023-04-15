#include "layer.hpp"

#include "genericFilter.hpp"
#include "emptyFilter/emptyFilter.hpp"
#include "boxFilter/boxFilter.hpp"
#include "medianFilter/medianFilter.hpp"
#include "gaussianFilter/gaussianFilter.hpp"
#include "bilateralFilter/bilateralFilter.hpp"
#include "dilateFilter/dilateFilter.hpp"
#include "erodeFilter/erodeFilter.hpp"
#include "sobelFilter/sobelFilter.hpp"
#include "cannyFilter/cannyFilter.hpp"
#include "embossFilter/embossFilter.hpp"
#include "lensFilter/lensFilter.hpp"

Layer::Layer(int initialIndex) {
    setupFilters();
    currentIndex = initialIndex;
}

Layer::~Layer() { allFilters.clear(); }

void Layer::setupFilters() {
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

void Layer::applyFilter(cv::Mat &inframe) {
    currentFilter = allFilters[currentIndex];
    currentFilter->applyFilter(inframe);
}
