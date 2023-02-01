#ifndef GENERIC_FILTER_H
#define GENERIC_FILTER_H

#include <opencv2/core.hpp>

class GenericFilterWrapper {
  private:
    int kernelSizeX;
    int kernelSizeY;

  public:
    explicit GenericFilterWrapper(int initialKernelSize);
    virtual void applyFilter(cv::Mat indrame);
    virtual void setKernelSize1D(int newKernelSize);
    virtual void setKernelSize2D(int newKernelSizeX, int newKernelSizeY);
    virtual int getKernelSize1D();
    virtual cv::Size getKernelSize2D();
};

#endif
