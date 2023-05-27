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
    roi = new Roi(QRectF(0, 0, VIEWPORT_WIDTH, VIEWPORT_HEIGHT));
    scene->addItem(roi);
    setSelected(false);
}

Layer::~Layer() {
    allFilters.clear();
    delete roi;
}

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
    width = roi->rect().width();
    height = roi->rect().height();

    if (height == 0 || width == 0) {
        return;
    }

    cv::Rect roi(x, y, width, height);
    cv::Mat outframe = inframe(roi);

    allFilters[currentIndex]->applyFilter(outframe);
    outframe.copyTo(inframe(roi));
}

void Layer::setSelected(bool isSelected) { roi->setSelected(isSelected); }

void Layer::setIndex(int newIndex) { currentIndex = newIndex; }

int Layer::getIndex() { return currentIndex; }

std::vector<GenericFilterWrapper *> Layer::getFilters() { return allFilters; }

GenericFilterWrapper *Layer::getCurrentFilter() { return allFilters[currentIndex]; }
