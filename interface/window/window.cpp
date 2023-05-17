#include "window.hpp"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    openCapture();
    startTimer();

    view = new QGraphicsView;
    scene = new QGraphicsScene;
    pixmap = scene->addPixmap(QPixmap::fromImage(image));
    scene->setSceneRect(0, 0, VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
    view->setFixedSize(VIEWPORT_WIDTH + 2 * ANCHOR_SIZE, VIEWPORT_HEIGHT + 2 * ANCHOR_SIZE);
    view->setScene(scene);
    view->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatioByExpanding);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    layers.push_back(new Layer(0, scene));

    sidebar = new Sidebar(&freezeFrame, &layers, scene);

    layout = new QHBoxLayout;
    layout->addWidget(sidebar);
    layout->addWidget(view);
    setLayout(layout);

    setWindowTitle("Image Processing Demo");
    show();
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

    freezeFrame = false;
    captureFrame();
}

void MainWindow::captureFrame() {
    if (freezeFrame) {
        return;
    }

    videoCap.read(liveImage);
    if (liveImage.empty()) {
        std::cerr << "ERROR! blank frame grabbed\n";
        exit(1);
    }
}

void MainWindow::startTimer() {
    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, this, [=](){Update();});
    timer->start(15);
}

void MainWindow::Update() {
    captureFrame();
    cv::Mat frame = cv::Mat(liveImage.size(), liveImage.type());
    liveImage.copyTo(frame);

    cv::resize(frame, frame, cv::Size(VIEWPORT_WIDTH, VIEWPORT_HEIGHT));
    for (Layer *layer : layers) {
        layer->applyFilter(frame);
    }
    image = cvMatToQImage(frame);
    pixmap->setPixmap(QPixmap::fromImage(image));
}
