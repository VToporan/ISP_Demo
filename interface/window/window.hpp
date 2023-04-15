#ifndef WINDOW_H
#define WINDOW_H

#include "layer/layer.hpp"

#include <opencv2/opencv.hpp>
#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
#include <QTimer>

#include <vector>

class MainWindow : QMainWindow {
        Q_OBJECT
    public:
        MainWindow();
        ~MainWindow(){};

        void startTimer();
        void openCapture();

    public slots:
        void Update();

    private:
        cv::VideoCapture videoCap;
        cv::Mat liveImage;
        QImage image;
        QLabel *label;
        std::vector<Layer *> layers;
};

#endif
