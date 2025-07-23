#include "MPCState.h"

void MPCState::handleRequest(DrumPadRequest request) {
    // Route drumpad requests
    switch (request.inputSignal.inputSignal) {
        case InputSignal::DRUMPAD_DOWN:
            handleDrumPadDown(request.drumpad);
            break;
        case InputSignal::DRUMPAD_HOLD:
            handleDrumPadHold(request.drumpad);
            break;
        case InputSignal::DRUMPAD_UP:
            handleDrumPadUp(request.drumpad);
            break;
        default:
            break;
    }
}

void MPCState::handleRequest(ButtonRequest request) {
    // Route button requests
    switch (request.inputSignal.inputSignal) {
        case InputSignal::BUTTON_DOWN:
            handleButtonDown(request.button);
            break;
        case InputSignal::BUTTON_UP:
            handleButtonUp(request.button);
            break;
        default:
            break;
    }
}