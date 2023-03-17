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

int wrapperIndex = 5;
int freezeFrame = false;
void CallBackFunc(int event, int x, int y, int flags, void *userdata) {
    if (event == cv::EVENT_LBUTTONDOWN) {
        freezeFrame = !freezeFrame;
    }
}

#include <QApplication>
#include <QLabel>
#include <QWidget>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QLabel hello("<center>Welcome to my first Qt program</center>");
    hello.setWindowTitle("My First Qt Program");
    hello.resize(400, 400);
    hello.show();
    return app.exec();
}
