#include "Input.h"

DrumPad::DrumPad(int id, int padNum) : Input(id), padNumber {padNum} {};

void DrumPad::setLightColour(RGB colour) {
    MPCController* mpc = MPCController::Instance();
    mpc->SetPadRGB(this, colour);
}