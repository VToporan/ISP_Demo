#ifndef WINDOW_H
#define WINDOW_H

#include <opencv2/opencv.hpp>

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QTimer>

class MainWindow : QMainWindow {
        Q_OBJECT
    public:
        MainWindow();
        ~MainWindow() {};

        void startTimer();
        void openCapture();

    public slots:
        void Update();

    private:
        cv::VideoCapture videoCap;
        cv::Mat liveImage;
        QImage image;
        QLabel *label;
};

#endif
