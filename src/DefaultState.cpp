#include "DefaultState.h"
#include "MPC.h"

void DefaultState::handleRequest(DrumPadRequest request) {
    if (request.signal == DrumPadSignal::DRUMPAD_DOWN) {
        request.drumpad->setLightOn();
        mpc->midi_send->setPadRGB(request.drumpad->padNumber, request.drumpad->getLightColour());
        mpc->audio.MakeSound();
    }
};

void DefaultState::handleRequest(ButtonRequest request) {
    if (request.signal == ButtonSignal::BUTTON_UP) {
        mpc->audio.MakeSound();
    }
};