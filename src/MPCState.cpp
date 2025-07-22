#include "MPCState.h"

void MPCState::handleRequest(DrumPadRequest request) {
    // Route drumpad requests
    switch (request.signal) {
        case DrumPadSignal::DRUMPAD_DOWN:
            handleDrumPadDown(request.drumpad);
            break;
        case DrumPadSignal::DRUMPAD_HOLD:
            handleDrumPadHold(request.drumpad);
            break;
        case DrumPadSignal::DRUMPAD_UP:
            handleDrumPadUp(request.drumpad);
            break;
        default:
            break;
    }
}

void MPCState::handleRequest(ButtonRequest request) {
    // Route button requests
    switch (request.signal) {
        case ButtonSignal::BUTTON_DOWN:
            handleButtonDown(request.button);
            break;
        case ButtonSignal::BUTTON_UP:
            handleButtonUp(request.button);
            break;
        default:
            break;
    }
}