#include "slider.hpp"

Slider::Slider(parameterConfig config) {
    currentValue = config.currentValue;
    slider = new QSlider;
    setConfig(config);

    QFont font = QFont("Courier New", 10);
    nameLabel = new QLabel(config.name);
    nameLabel->setFont(font);
    valueLabel = new QLabel(QString("%1").arg(currentValue, 3));
    valueLabel->setFont(font);

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(nameLabel, 0, 0, 1, 1);
    grid->addWidget(slider, 1, 0, 1, 1);
    grid->addWidget(valueLabel, 1, 1, 1, 1);

    setLayout(grid);
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

    int tickAmount = (config.maxValue - config.minValue) / config.step;
    if (tickAmount >= 50) {
        slider->setTickInterval(config.step * 10);
    }
    if (tickAmount >= 500) {
        slider->setTickInterval(config.step * 50);
    }

    connect(slider, &QSlider::valueChanged, this, [=]() {
        int newValue = slider->value();
        int step = slider->singleStep();
        int diff = currentValue - newValue;

        if (diff == 0) {
            return;
        }

        int offset = diff % step;
        if (offset != 0) {
            slider->setValue(newValue + offset);
            return;
        }

        currentValue = newValue;
        valueLabel->setText(QString("%1").arg(currentValue, 3));
        config.setter(currentValue);
    });
}
