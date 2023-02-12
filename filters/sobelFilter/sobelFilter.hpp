#ifndef SOBEL_FILTER_H
#define SOBEL_FILTER_H

#include "genericFilter.hpp"
#include <opencv2/core.hpp>

class SobelFitlerWrapper : public GenericFilterWrapper {
  private:
    int kernelSize;
    int derivX;
    int derivY;
    bool displayDirection;

  public:
    explicit SobelFitlerWrapper(int initialKernelSize);
    explicit SobelFitlerWrapper(int initialKernelSize, int initialDerivate);
    explicit SobelFitlerWrapper(int initialKernelSize, int initialDerivateX,
                                int initialDerivateY);

    void setKernelSize2D(int newKernelSizeX, int newKernelSizeY);
    void setKernelSize1D(int newKernelSize);
    int getKernelSize1D();
    cv::Size getKernelSize2D();

    void setDerivX(int newDerivX);
    void setDerivY(int newDerivY);
    int getDerivX();
    int getDerivY();

    void toggleDisplayDirection();

    void applyFilter(cv::Mat& inframe);
};

#endif
