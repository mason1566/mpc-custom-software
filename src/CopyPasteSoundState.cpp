#include "CopyPasteSoundState.h"
#include "MPC.h"

// Public Handlers
// void CopyPasteSoundState::handleRequest(DrumPadRequest request) {
//     if (request.signal == DrumPadSignal::DRUMPAD_DOWN) {
//         request.drumpad->setLightOn();
//         mpc->midi_send->setPadRGB(request.drumpad->padNumber, request.drumpad->getLightColour());
//         mpc->audio.MakeSound();
//     }
// };

void CopyPasteSoundState::handleRequest(ButtonRequest request) {
    if (request.signal == ButtonSignal::BUTTON_UP) {
        mpc->audio.MakeSound();
    }
};


// Protected Input Handlers
void CopyPasteSoundState::handleDrumPadDown(DrumPad* drumpad) {
     
}

void CopyPasteSoundState::handleDrumPadHold(DrumPad* drumpad) {

}

void CopyPasteSoundState::handleDrumPadUp(DrumPad* drumpad) {

}

void CopyPasteSoundState::handleButtonDown(Button* button) {

}

void CopyPasteSoundState::handleButtonUp(Button* button) {

}