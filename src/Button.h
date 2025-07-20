#ifndef BUTTON
#define BUTTON
#include "Input.h"

class Button : public Input {
public:
    Button(int midiCode) : Input(midiCode) {}
};

#endif