#include "genericFilter.hpp"
#include "boxFilter.hpp"
#include "medianFilter.hpp"
#include "gaussianFilter.hpp"
#include <opencv2/opencv.hpp>
#include <stdio.h>
using namespace cv;
using namespace std;

VideoCapture cap;

void openCapture(int deviceID, int apiID) {
    cap.open(deviceID, apiID);
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        exit(-1);
    }
}

int main(int, char**) {
    Mat inframe;

    int deviceID = 0;
    int apiID = cv::CAP_ANY;
    int ddepth = -1;
    int kernel_size = 5;
    Mat kernel = getStructuringElement(
        MORPH_RECT, Size(2 * kernel_size + 1, 2 * kernel_size + 1),
        Point(kernel_size, kernel_size));

    openCapture(deviceID, apiID);

    cap.read(inframe);

    if (inframe.empty()) {
        cerr << "ERROR! blank frame grabbed\n";
        return -1;
    }

    // MedianFitlerWrapper medianFilterWrapper(-5);
    // medianFilterWrapper.applyFilter(inframe);
    //
    // BoxFitlerWrapper boxFilterWrapper(6);
    // boxFilterWrapper.applyFilter(inframe);

    GaussianFitlerWrapper gaussianFilterWrapper(15, 3, 30);
    gaussianFilterWrapper.applyFilter(inframe);

    imshow("out", inframe);
    waitKey(0);

    return 0;
}
