#include "CopyPasteSoundState.h"
#include "MPC.h"

// Protected Input Handlers
void CopyPasteSoundState::handleDrumPadDown(DrumPad* drumpad) {
    if (!drumpad) return;
    
    if (!drumpad1) {
        drumpad1 = drumpad;
        return;
    } else if (drumpad != drumpad1) {
        drumpad2 = drumpad;
        performCopyPaste();
    }
}

void CopyPasteSoundState::handleDrumPadHold(DrumPad* drumpad) {

}

void CopyPasteSoundState::handleDrumPadUp(DrumPad* drumpad) {

}

void CopyPasteSoundState::handleButtonDown(Button* button) {

}

void CopyPasteSoundState::handleButtonUp(Button* button) {

}

void CopyPasteSoundState::performCopyPaste() {
    if (!drumpad1 || !drumpad2) 
        return;

    drumpad1->setLightOn();
    drumpad2->setLightOn();
    drumpad2->setLightColour(drumpad1->getLightColour());
    mpc->midi_send->setPadRGB(drumpad1->padNumber, drumpad1->getLightColour());
    mpc->midi_send->setPadRGB(drumpad2->padNumber, drumpad2->getLightColour());

    drumpad1 = nullptr;
    drumpad2 = nullptr;
}