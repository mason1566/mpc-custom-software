#ifndef BUTTON_REQUEST
#define BUTTON_REQUEST

#include "Button.h"
#include "MidiInputSignal.h"

class ButtonRequest {
public:
    Button* button = nullptr;
    MidiInputSignal inputSignal;

    ButtonRequest(Button* button, MidiInputSignal inputSignal) : button(button), inputSignal(inputSignal) {}
};

#endif