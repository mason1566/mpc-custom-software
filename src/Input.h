#ifndef INPUT
#define INPUT

#include "RGB.h"

class Input {
public:
    int midiCode;
    
    Input(int midiCode) : midiCode(midiCode) {}
};

#endif