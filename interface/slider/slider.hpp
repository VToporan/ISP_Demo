#ifndef SLIDER_H
#define SLIDER_H

#include "genericFilter.hpp"

#include <QHBoxLayout>
#include <QSlider>

class Slider : public QWidget {
        Q_OBJECT;

    public:
        Slider(parameterConfig config);

    private:
        QSlider *slider;
        int currentValue;

        void setConfig(parameterConfig config);
};

#endif
