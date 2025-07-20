#ifndef BUTTON
#define BUTTON
#include "Input.h"

class Button : public Input {
public:
    Button(int midiCode) : Input(midiCode, MPC_CONSTANTS::INPUT_TYPES::BUTTON_INPUT) {}
};

#endif