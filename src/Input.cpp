#include "Input.h"

void DrumPad::setLightColour(RGB colour) {
    _lightColour = colour;
    MidiController::Instance()->SetPadRGB(padNumber, colour);
};