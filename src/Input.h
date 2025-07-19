#ifndef INPUT
#define INPUT

#include "RGB.h"

class Input {
public:
    int midiCode;
    
    Input(int midiCode) : midiCode(midiCode) {}
};

class Button : public Input {
public:
    Button(int midiCode) : Input(midiCode) {}
};

class DrumPad : public Input {
public:
    int padNumber; // MPC signals involving drumpad use idCode for incoming and padNumber for outgoing
    bool isLightOn = true;

    DrumPad(int midiCode, int padNum) : Input(midiCode), padNumber(padNum) {}
    void setLightColour(RGB colour) { _lightColour = colour; }
    RGB getLightColour();
    void toggleLight();
protected:
    RGB _lightColour { RGB::WHITE };
};

#endif