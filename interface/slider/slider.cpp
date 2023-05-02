#include "slider.hpp"

#include <QFont>
#include <QSplitter>
Slider::Slider(parameterConfig config) {
    currentValue = config.currentValue;
    slider = new QSlider;
    setConfig(config);

    nameLabel = new QLabel(config.name);
    valueLabel = new QLabel(QString("%1").arg(currentValue));

    QVBoxLayout *layoutVertical = new QVBoxLayout;
    layoutVertical->addWidget(nameLabel);

    QSplitter *layoutHorizontal = new QSplitter;
    layoutHorizontal->addWidget(slider);
    layoutHorizontal->addWidget(valueLabel);


    layoutVertical->addWidget(layoutHorizontal);
    setLayout(layoutVertical);
    setMaximumHeight(64);
}

void Slider::setConfig(parameterConfig config) {
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
        valueLabel->setText(QString("%1").arg(currentValue));
        config.setter(currentValue);
    });
}
