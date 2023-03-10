#include "bilateralFilter.hpp"
#include "boxFilter.hpp"
#include "cannyFilter.hpp"
#include "dilateFilter.hpp"
#include "embossFilter.hpp"
#include "erodeFilter.hpp"
#include "gaussianFilter.hpp"
#include "genericFilter.hpp"
#include "lensFilter.hpp"
#include "medianFilter.hpp"
#include "sobelFilter.hpp"

#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string>

#define DEVICE_ID (0)
#define API_ID (cv::CAP_ANY)

cv::VideoCapture cap;

void openCapture() {
    int deviceID = 0;
    int apiID = cv::CAP_ANY;
    int ddepth = -1;

    cap.open(deviceID, apiID);
    if (!cap.isOpened()) {
        std::cerr << "ERROR! Unable to open camera\n";
        exit(-1);
    }
}

int main(int, char **) {
    cv::Mat inframe;

    openCapture();

    MedianFitlerWrapper medianFilterWrapper(5);
    BoxFitlerWrapper boxFilterWrapper(6);
    GaussianFitlerWrapper gaussianFilterWrapper(15, 3, 30);
    BilateralFitlerWrapper bilateralFilterWrapper(1, 1, 1);
    ErodeFitlerWrapper erodeFilterWrapper(10);
    DilateFitlerWrapper dilateFilterWrapper(10);
    SobelFitlerWrapper sobelFilterWrapper(3, 1, 1);
    CannyFitlerWrapper cannyFitlerWrapper(3, 15);
    EmbossFitlerWrapper embossFitlerWrapper;
    LensFitlerWrapper lensFilterWrapper(3);

    GenericFilterWrapper *wrappers[] = {
        &medianFilterWrapper, &boxFilterWrapper,   &gaussianFilterWrapper, &bilateralFilterWrapper, &erodeFilterWrapper,
        &dilateFilterWrapper, &sobelFilterWrapper, &cannyFitlerWrapper,    &embossFitlerWrapper,    &lensFilterWrapper,
    };

    sobelFilterWrapper.toggleDisplayDirection();

    bool keepGoing = false;
    do {
        cap.read(inframe);

        if (inframe.empty()) {
            std::cerr << "ERROR! blank frame grabbed\n";
            return -1;
        }

        int wrapperArrSize = sizeof(wrappers) / sizeof(wrappers[0]);
        for (int i = 4; i < wrapperArrSize; ++i) {
            cv::Mat outframe = inframe.clone();
            wrappers[i]->applyFilter(outframe);
            imshow("out" + std::to_string(i), outframe);
            cv::moveWindow("out" + std::to_string(i), (i / 2) * 400, (i % 2) * 500);
        }
        if (cv::waitKey(0) == ' ') {
            keepGoing = false;
        }
    } while (keepGoing);
    return 0;
}
