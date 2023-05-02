#ifndef SLIDER_H
#define SLIDER_H

#include "genericFilter.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>

class Slider : public QWidget {
        Q_OBJECT;

    public:
        Slider(parameterConfig config);

    private:
        QSlider *slider;
        QLabel *nameLabel;
        QLabel *valueLabel;
        int currentValue;

        void setConfig(parameterConfig config);
};

#endif