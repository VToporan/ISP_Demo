#ifndef LAYER_H
#define LAYER_H

#include "genericFilter.hpp"
#include "roi/roi.hpp"

#include <QGraphicsScene>
#include <vector>

class Layer {
    public:
        Layer(int initialIndex, QGraphicsScene *scene);
        ~Layer();
        void setupFilters();
        void applyFilter(cv::Mat &inframe);
        void setSelected(bool isSelected);
        void setIndex(int newIndex);
        int getIndex();
        GenericFilterWrapper* getCurrentFilter();
        std::vector<GenericFilterWrapper *> getFilters();

    private:
        std::vector<GenericFilterWrapper *> allFilters;
        Roi *roi;
        int currentIndex;
};

#endif
