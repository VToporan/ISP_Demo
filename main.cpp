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
#define WINDOW_NAME ("ISP Demo")

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

int wrapperIndex = 0;
bool freezeFrame = false;
void CallBackFunc(int event, int x, int y, int flags, void *userdata) {
    if (event == cv::EVENT_LBUTTONDOWN) {
        freezeFrame = !freezeFrame;
    }
}

int main(int, char **) {
    cv::Mat inframe;

    openCapture();

    MedianFitlerWrapper medianFilterWrapper(5);
    BoxFitlerWrapper boxFilterWrapper(9);
    GaussianFitlerWrapper gaussianFilterWrapper(15, 3, 30);
    BilateralFitlerWrapper bilateralFilterWrapper(3, 3, 3);
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
    int wrapperTotal = sizeof(wrappers) / sizeof(wrappers[0]);

    bool keepGoing = true;

    cv::namedWindow(WINDOW_NAME, cv::WINDOW_NORMAL | cv::WINDOW_FREERATIO | cv::WINDOW_GUI_EXPANDED);
    cv::resizeWindow(WINDOW_NAME, 1920, 1080);
    cv::setMouseCallback(WINDOW_NAME, CallBackFunc);
    do {
        if (!freezeFrame) {
            cap.read(inframe);

            if (inframe.empty()) {
                std::cerr << "ERROR! blank frame grabbed\n";
                return -1;
            }
        }

        cv::Mat outframe = inframe.clone();
        wrappers[wrapperIndex]->applyFilter(outframe);
        cv::resize(outframe, outframe, cv::Size(1240, 1080));
        cv::imshow(WINDOW_NAME, outframe);
        if (cv::waitKey(5) == ' ') {
            wrapperIndex++;
        }
        if (wrapperIndex >= 3) {
            keepGoing = false;
        }
    } while (keepGoing);
    return 0;
}
