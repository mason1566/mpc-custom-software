#ifndef BUTTON
#define BUTTON
#include "Input.h"

class Button : public Input {
public:
    Button(int midiCode, std::string name) : Input(midiCode, MPC_CONSTANTS::INPUT_TYPES::BUTTON_INPUT, name) {}
};

#endif