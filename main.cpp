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

#include "window.hpp"

#define DEVICE_ID (0)
#define API_ID (cv::CAP_ANY)
#define WINDOW_NAME ("ISP Demo")

int wrapperIndex = 5;
int freezeFrame = false;
void CallBackFunc(int event, int x, int y, int flags, void *userdata) {
    if (event == cv::EVENT_LBUTTONDOWN) {
        freezeFrame = !freezeFrame;
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow *window = new MainWindow();
    return app.exec();
}

#include "main.moc"
