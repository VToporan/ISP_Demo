#ifndef EMBOSS_FILTER_H
#define EMBOSS_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

enum EmbossDirection {
    EMBOSS_DIRECTION_UP,
    EMBOSS_DIRECTION_LEFT,
    EMBOSS_DIRECTION_RIGHT,
    EMBOSS_DIRECTION_DOWN,

    EMBOSS_DIRECTION_TOTAL
};

class EmbossFitlerWrapper : public GenericFilterWrapper {
  private:
    EmbossDirection currentDirection;
    cv::Mat embossKernels[EMBOSS_DIRECTION_TOTAL];

  public:
    explicit EmbossFitlerWrapper();
    void setEmbossDirection(EmbossDirection newDirection);

    void applyFilter(cv::Mat& inframe);
};

#endif
