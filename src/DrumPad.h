#ifndef DRUMPAD
#define DRUMPAD

#include "BaseInput.h"
#include "RGB.h"

class DrumPad : public BaseInput {
public:
    int padNumber; // MPC signals involving drumpad use idCode for incoming and padNumber for outgoing
    bool isLightOn = true;

    DrumPad(int midiCode, int padNum) : BaseInput(midiCode, MPC_CONSTANTS::INPUT_TYPES::DRUMPAD_INPUT), padNumber(padNum), _lightColour(RGB::WHITE) {}
    void setLightColour(RGB colour) { _lightColour = colour; }
    RGB getLightColour();
    void toggleLight();
    void setLightOff() { isLightOn = false; }
    void setLightOn() { isLightOn = true; }
protected:
    RGB _lightColour;
};

#endif