#ifndef DRUMPAD
#define DRUMPAD

#include "BaseInput.h"
#include "../utility/RGB.h"
#include "../sounds/Sound.h"

class DrumPad : public BaseInput {
public:
    int padNumber; // MPC signals involving drumpad use idCode for incoming and padNumber for outgoing
    bool isLightOn = true;
    int velocity = 0;
    Sound* sound = nullptr;

    DrumPad(int midiValue, int padNum) : BaseInput(midiValue), padNumber(padNum), _lightColour(RGB::WHITE) {}
    void setLightColour(RGB colour) { _lightColour = colour; }
    RGB getLightColour();
    void toggleLight();
    void setLightOff() { isLightOn = false; }
    void setLightOn() { isLightOn = true; }
    RGB _lightColour;
};

#endif