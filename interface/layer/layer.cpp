#include "layer.hpp"

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

Layer::Layer(int initialIndex, QGraphicsScene *scene) {
    setupFilters();
    currentIndex = initialIndex;
    roi = new Roi(QRectF(10, 10, 100, 100));
    scene->addItem(roi);
    setSelected(false);
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
    QPointF origin = roi->mapToScene(roi->rect().x(), roi->rect().y());
    qreal x = 0, y = 0, width = 0, height = 0;
    x = origin.x();
    y = origin.y();
    width = roi->rect().width() + 1;
    height = roi->rect().height() + 1;

    cv::Rect roi(x, y, width, height);
    cv::Mat outframe = inframe(roi);

    allFilters[currentIndex]->applyFilter(outframe);
    outframe.copyTo(inframe(roi));
}

void Layer::setSelected(bool isSelected) {
    roi->setSelected(isSelected);
    if (isSelected) {
        setSliders();
    } else {
        clearSliders();
    }
}

void Layer::setSliders() {
    for (parameterConfig config : allFilters[currentIndex]->allParameterConfigs()) {
        sliders.push_back(new Slider(config));
    }
}

void Layer::clearSliders() {
    for (Slider *slider : sliders) {
        delete slider;
    }
    sliders.clear();
}

std::vector<Slider *> Layer::getSliders() { return sliders; }
