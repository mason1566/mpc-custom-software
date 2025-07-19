#ifndef INPUT
#define INPUT

#include "RGB.h"

class Input {
public:
    int idCode;
    
    Input(int id) : idCode {id} {};
};

class Button : Input {
public:
    Button(int id) : Input(id) {};
};

class DrumPad : Input {
public:
    int padNumber; // MPC signals involving drumpad use idCode for incoming and padNumber for outgoing
    bool isLightOn;

    DrumPad(int id, int padNum) : Input(id), padNumber {padNum} {};;
    void setLightColour(RGB colour) { _lightColour = colour; };
    RGB getLightColour() { return _lightColour; };
protected:
    RGB _lightColour { RGB::WHITE };
};

#endif