#include "layer.hpp"

#include "genericFilter.hpp"
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

Layer::Layer() {
    allFilters.push_back(new BoxFitlerWrapper(3));
    allFilters.push_back(new MedianFitlerWrapper(3));
    allFilters.push_back(new GaussianFitlerWrapper(3));
    allFilters.push_back(new BilateralFitlerWrapper(3));
    allFilters.push_back(new DilateFitlerWrapper(3));
    allFilters.push_back(new ErodeFitlerWrapper(3));
    allFilters.push_back(new SobelFitlerWrapper(3));
    allFilters.push_back(new CannyFitlerWrapper(3));
    allFilters.push_back(new ErodeFitlerWrapper(3));
    allFilters.push_back(new LensFitlerWrapper(3));
}

Layer::~Layer() { allFilters.clear(); }

void Layer::applyFilter(cv::Mat &inframe) {
    currentFilter = allFilters[4];
    currentFilter->applyFilter(inframe);
}
