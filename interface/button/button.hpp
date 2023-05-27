#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <functional>

class Button : public QPushButton {
    public:
        Button(const char *text, uint height, QFont font);
};

#endif
