#ifndef WINDOW_H
#define WINDOW_H

#include "layer/layer.hpp"
#include "sidebar/sidebar.hpp"
#include "style.hpp"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QPixmap>
#include <QTimer>
#include <QWidget>
#include <opencv2/opencv.hpp>

#include <vector>

class MainWindow : QWidget {

    public:
        MainWindow(QWidget *parent);

        void startTimer();
        void openCapture();
        void captureFrame();

        void Update();

    private:
        cv::VideoCapture videoCap;
        cv::Mat liveImage;
        QImage image;
        QGraphicsPixmapItem *pixmap;
        bool freezeFrame;

        QHBoxLayout *layout;
        QGraphicsView *view;
        QGraphicsScene *scene;
        Sidebar *sidebar;
        std::vector<Layer *> layers;
};

#endif
