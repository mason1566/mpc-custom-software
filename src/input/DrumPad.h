#ifndef DRUMPAD
#define DRUMPAD

#include "BaseInput.h"
#include "../utility/RGB.h"
#include "../sounds/DrumPadSound.h"

#include <memory>

class DrumPad : public BaseInput {
public:
    int padNumber; // MPC signals involving drumpad use idCode for incoming and padNumber for outgoing
    bool isLightOn = true;
    int velocity = 0;
    std::unique_ptr<DrumPadSound> sound = nullptr;
    RGB _lightColour;

    DrumPad(int midiValue, int padNum) : BaseInput(midiValue), padNumber(padNum), _lightColour(RGB::WHITE) {}
    void setLightColour(RGB colour) { _lightColour = colour; }
    RGB getLightColour();
    void toggleLight();
    void setLightOff() { isLightOn = false; }
    void setLightOn() { isLightOn = true; }
};

#endif