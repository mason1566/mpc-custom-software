#include "DefaultState.h"
#include "MPC.h"
#include "Utility.h"

// void DefaultState::handleRequest(DrumPadRequest request) {
//     if (request.signal == DrumPadSignal::DRUMPAD_DOWN) {
//         request.drumpad->setLightOn();
//         mpc->midi_send->setPadRGB(request.drumpad->padNumber, request.drumpad->getLightColour());
//         mpc->audio.MakeSound();
//     }
// };

void DefaultState::handleRequest(ButtonRequest request) {
    if (request.signal == ButtonSignal::BUTTON_UP) {
        mpc->audio.MakeSound();
    }
};

// Protected Input Handlers
void DefaultState::handleDrumPadDown(DrumPad* drumpad) {
    drumpad->setLightOn();
    mpc->midi_send->setPadRGB(drumpad->padNumber, drumpad->getLightColour());
    mpc->audio.MakeSound();
}

void DefaultState::handleDrumPadHold(DrumPad* drumpad) {

}

void DefaultState::handleDrumPadUp(DrumPad* drumpad) {

}

void DefaultState::handleButtonDown(Button* button) {
    std::cout << button->midiCode << std::endl;
    if (button->midiCode == MPC_CONSTANTS::BUTTON_MIDI_VALUES::COPY) {
        mpc->midi_send->setPadRGB(0, RGB::GREEN);
    }
}

void DefaultState::handleButtonUp(Button* button) {

}