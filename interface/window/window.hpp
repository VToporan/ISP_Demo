#ifndef WINDOW_H
#define WINDOW_H

#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <QApplication>
#include <QGraphicsScene>
#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
#include <QTimer>
#include <QWidget>

class MainWindow : QMainWindow {
        Q_OBJECT
    public:
        MainWindow() {
            openCapture();
            startTimer();
        }
        ~MainWindow() {};

        void startTimer();
        void openCapture();

    public slots:
        void Update();

    private:
        cv::VideoCapture videoCap;
        cv::Mat liveImage;
        QImage image;
        QLabel *label = new QLabel;
};

#endif
