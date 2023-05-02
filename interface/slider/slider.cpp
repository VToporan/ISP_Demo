#include "slider.hpp"

Slider::Slider(parameterConfig config) {
    currentValue = config.currentValue;
    slider = new QSlider;
    setConfig(config);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(slider);
    setLayout(layout);
}

void Slider::setConfig(parameterConfig config) {
    slider->setFixedHeight(50);
    slider->setOrientation(Qt::Horizontal);
    slider->setTickPosition(QSlider::TicksBelow);
    slider->setMinimum(config.minValue);
    slider->setMaximum(config.maxValue);
    slider->setTickInterval(config.step);
    slider->setSingleStep(config.step);
    slider->setValue(config.currentValue);

    connect(slider, &QSlider::valueChanged, this, [=]() {
        int newValue = slider->value();

        if (newValue == currentValue) {
            return;
        }

        int offset = (currentValue - newValue) % slider->singleStep();
        if (offset != 0) {
            slider->setValue(newValue + offset);
            return;
        }

        currentValue = newValue;
        config.setter(currentValue);
    });
}
