#ifndef BUTTON
#define BUTTON

#include "BaseInput.h"
#include "RGB.h"

class Button : public BaseInput {
public:
    Button(int midiValue) : BaseInput(midiValue) {}
};

#endif