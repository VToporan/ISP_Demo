#include "window.hpp"

MainWindow::MainWindow() {
    openCapture();
    startTimer();
    label = new QLabel;
}

void MainWindow::openCapture() {
    int deviceID = 0;
    int apiID = cv::CAP_ANY;
    int ddepth = -1;

    videoCap.open(deviceID, apiID);
    if (!videoCap.isOpened()) {
        std::cerr << "ERROR! Unable to open camera\n";
        exit(-1);
    }
}

void MainWindow::startTimer() {
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Update()));
    timer->start(10);
}

void MainWindow::Update() {
    cv::Mat frame;
    videoCap.read(frame);
    if (frame.empty()) {
        std::cerr << "ERROR! blank frame grabbed\n";
        exit(1);
    }

    image = QImage(frame.data, frame.cols, frame.rows, QImage::Format_RGB888).rgbSwapped();
    label->setPixmap(QPixmap::fromImage(image));

    label->show();
}
