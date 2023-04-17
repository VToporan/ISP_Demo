#ifndef WINDOW_H
#define WINDOW_H

#include "layer/layer.hpp"

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <QPixmap>
#include <QRect>
#include <QTimer>
#include <opencv2/opencv.hpp>

#include <vector>

class MainWindow : QMainWindow {
        Q_OBJECT
    public:
        MainWindow(QWidget *parent);
        ~MainWindow(){};

        void startTimer();
        void openCapture();

    public slots:
        void Update();

    private:
        cv::VideoCapture videoCap;
        cv::Mat liveImage;
        QImage image;
        QGraphicsScene *scene;
        QGraphicsView *view;
        QGraphicsPixmapItem *pixmap;
        std::vector<Layer *> layers;
};

#endif
