#ifndef GAUSSIAN_FILTER_H
#define GAUSSIAN_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class GaussianFitlerWrapper : public GenericFilterWrapper {
  private:
    double sigmaX;
    double sigmaY;

  public:
    explicit GaussianFitlerWrapper(int initialKernelSize);
    explicit GaussianFitlerWrapper(int initialKernelSize, double initialSigma);
    explicit GaussianFitlerWrapper(int initialKernelSize, double initialSigmaX,
                                   double initialSigmaY);
    void setSigma(int newSigma);
    void setSigmaX(int newSigmaX);
    void setSigmaY(int newSigmaY);
    double getSigmaX();
    double getSigmaY();
    void applyFilter(cv::Mat& inframe);
};

#endif
