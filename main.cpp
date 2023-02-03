#include "bilateralFilter.hpp"
#include "boxFilter.hpp"
#include "cannyFilter.hpp"
#include "dilateFilter.hpp"
#include "erodeFilter.hpp"
#include "gaussianFilter.hpp"
#include "genericFilter.hpp"
#include "medianFilter.hpp"
#include "sobelFilter.hpp"

#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string>

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

    MedianFitlerWrapper medianFilterWrapper(5);
    BoxFitlerWrapper boxFilterWrapper(6);
    GaussianFitlerWrapper gaussianFilterWrapper(15, 3, 30);
    BilateralFitlerWrapper bilateralFilterWrapper(10, 10, 10);
    ErodeFitlerWrapper erodeFilterWrapper(10);
    DilateFitlerWrapper dilateFilterWrapper(10);
    SobelFitlerWrapper sobelFilterWrapper(3, 1, 1);
    CannyFitlerWrapper cannyFitlerWrapper(3, 15);

    GenericFilterWrapper* wrappers[] = {
        &medianFilterWrapper,    &boxFilterWrapper,   &gaussianFilterWrapper,
        &bilateralFilterWrapper, &erodeFilterWrapper, &dilateFilterWrapper,
        &sobelFilterWrapper,     &cannyFitlerWrapper};

    int wrapperArrSize = sizeof(wrappers) / sizeof(wrappers[0]);
    for (int i = 0; i < wrapperArrSize; ++i) {
        cv::Mat outframe = inframe.clone();
        wrappers[i]->applyFilter(outframe);
        imshow("out" + to_string(i), outframe);
    }
    waitKey();
    return 0;
}
