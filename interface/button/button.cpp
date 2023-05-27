#include "button.hpp"
#include "qpushbutton.h"

Button::Button(const char *text, uint height, QFont font) : QPushButton(text) {
    setFixedHeight(height);
    setFont(font);
}
