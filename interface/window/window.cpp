#include "window.hpp"

MainWindow::MainWindow() {
    openCapture();
    startTimer();
    label = new QLabel;
    layers.push_back(new Layer(0));
    layers.push_back(new Layer(7));
}

// https://asmaloney.com/2013/11/code/converting-between-cvmat-and-qimage-or-qpixmap
static inline QImage cvMatToQImage(const cv::Mat &inMat) {
    switch (inMat.type()) {
    // 8-bit, 4 channel
    case CV_8UC4: {
        QImage image(inMat.data, inMat.cols, inMat.rows, static_cast<int>(inMat.step), QImage::Format_ARGB32);
        return image;
    }
    // 8-bit, 3 channel
    case CV_8UC3: {
        QImage image(inMat.data, inMat.cols, inMat.rows, static_cast<int>(inMat.step), QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    // 8-bit, 1 channel
    case CV_8UC1: {
        static QVector<QRgb> sColorTable;
        // only create our color table the first time
        if (sColorTable.isEmpty()) {
            sColorTable.resize(256);

            for (int i = 0; i < 256; ++i) {
                sColorTable[i] = qRgb(i, i, i);
            }
        }
        QImage image(inMat.data, inMat.cols, inMat.rows, static_cast<int>(inMat.step), QImage::Format_Indexed8);
        image.setColorTable(sColorTable);
        return image;
    }
    default:
        break;
    }
    return QImage();
}

void MainWindow::openCapture() {
    int deviceID = 0;
    int apiID = cv::CAP_ANY;

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

    for (Layer *layer : layers) {
        layer->applyFilter(frame);
    }
    image = cvMatToQImage(frame);
    label->setPixmap(QPixmap::fromImage(image));

    label->show();
}
