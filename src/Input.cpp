#include "Input.h"

RGB DrumPad::getLightColour() {
    if (!isLightOn)
        return RGB::BLACK;
    else
        return _lightColour;
}

void DrumPad::toggleLight() {
    if (isLightOn) {
        isLightOn = false;
    }
    else {
        isLightOn = true;
    }
}