#include "DefaultState.h"
#include "../Utility.h"

// void DefaultState::handleRequest(DrumPadRequest request) {
//     if (request.signal == DrumPadSignal::DRUMPAD_DOWN) {
//         request.drumpad->setLightOn();
//         mpc->midi_send->setPadRGB(request.drumpad->padNumber, request.drumpad->getLightColour());
//         mpc->audio.MakeSound();
//     }
// };

// Protected Input Handlers
void DefaultState::handleDrumPadDown(DrumPad* drumpad) {

}

void DefaultState::handleDrumPadHold(DrumPad* drumpad) {

}

void DefaultState::handleDrumPadUp(DrumPad* drumpad) {

}

void DefaultState::handleButtonDown(Button* button) {

}

void DefaultState::handleButtonUp(Button* button) {

}