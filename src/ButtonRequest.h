#ifndef BUTTON_REQUEST
#define BUTTON_REQUEST

#include "Button.h"

enum class ButtonSignal {
    BUTTON_DOWN,
    BUTTON_UP
};

class ButtonRequest {
public:
    Button* button = nullptr;
    ButtonSignal signal;

    ButtonRequest(Button* button, ButtonSignal signal) : button(button), signal(signal) {}
};

#endif