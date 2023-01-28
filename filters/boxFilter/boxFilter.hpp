#ifndef BOX_FILTER_H
#define BOX_FILTER_H

#include <opencv2//core.hpp>

class BoxFitlerWrapper {
    public:
        void applyFilter(cv::Mat &inframe);
};

#endif
