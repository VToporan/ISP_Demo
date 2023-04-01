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

#include <cstdlib>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <QApplication>
#include <QGraphicsScene>
#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
#include <QTimer>
#include <QWidget>

#include <qwindowdefs.h>
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

class MainWindow : QMainWindow {
        Q_OBJECT
    public:
        MainWindow() {}

        ~MainWindow() {}
        void start() {
            QTimer *timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), this, SLOT(Update()));
            timer->start(20);
        }

    public slots:
        void Update();

    private:
        cv::VideoCapture videoCap;
        cv::Mat liveImage;
        QImage image;
        QLabel *label = new QLabel;
};

void MainWindow::Update() {
    cv::Mat frame;
    cap.read(frame);
    if (frame.empty()) {
        std::cerr << "ERROR! blank frame grabbed\n";
        exit(1);
    }
    LensFitlerWrapper lensFilter = LensFitlerWrapper(-0.4);
    lensFilter.applyFilter(frame);

    image = QImage(frame.data, frame.cols, frame.rows, QImage::Format_RGB888).rgbSwapped();
    label->setPixmap(QPixmap::fromImage(image));

    label->show();
}

int main(int argc, char *argv[]) {
    openCapture();
    QApplication app(argc, argv);
    MainWindow *window = new MainWindow();
    window->start();
    return app.exec();
}

#include "main.moc"
