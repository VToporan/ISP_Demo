#ifndef SLIDER_H
#define SLIDER_H

#include "genericFilter.hpp"

#include <QSlider>
#include <iostream>

class Slider : public QSlider {
    public:
        Slider(parameterConfig config) {
            setFixedHeight(50);
            setOrientation(Qt::Horizontal);
            setTickPosition(QSlider::TicksBelow);
            setMinimum(config.minValue);
            setMaximum(config.maxValue);
            setTickInterval(config.step);
            setSingleStep(config.step);
            setValue(config.currentValue);

            connect(this, &QSlider::valueChanged, this, [=]() {
                config.setter(value());
            });
        }

    private:
        int currentValue = value();
};

#endif
