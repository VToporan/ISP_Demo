#ifndef SLIDER_H
#define SLIDER_H

#include <QSlider>
#include <iostream>

class Slider : public QSlider {
    public:
        Slider() {
            setFixedHeight(50);
            setOrientation(Qt::Horizontal);
            setTickPosition(QSlider::TicksBelow);
            setMaximum(50);
            setMinimum(-50);
            setTickInterval(3);
            setSingleStep(3);
            connect(this, &QSlider::valueChanged, this, [=]() {
                if (value() == currentValue) {
                    return;
                }
                int offset = value() % singleStep();
                if (offset) {
                    int newValue = value() - (value() % singleStep());
                    currentValue = newValue;
                    setValue(newValue);
                    return;
                }
                std::cout << value() << "\n";
            });
        }

    private:
        int currentValue = value();
};

#endif
