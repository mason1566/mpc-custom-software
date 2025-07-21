#ifndef BUTTON
#define BUTTON

#include "BaseInput.h"
#include "RGB.h"

class Button : public BaseInput {
public:
    Button(int midiCode) : BaseInput(midiCode, MPC_CONSTANTS::INPUT_TYPES::BUTTON_INPUT) {}
};

#endif