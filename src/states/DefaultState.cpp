#include "DefaultState.h"

#include <iostream>

StateAction DefaultState::handleInput(const InputEvent& inputEvent) {
    State::handleInput(inputEvent);
    return StateAction::None;
};

StateAction DefaultState::handleDrumPadInput(const InputEvent& inputEvent) {
    DrumPad* drumpad = input.drum_map[inputEvent.midiValue];

    switch (inputEvent.inputSignal) 
    {
        case InputSignal::DRUMPAD_DOWN:
        {
            activeDrumPad = drumpad;
            drumpad->setLightOn();
            midiSend.setPadRGB(drumpad->padNumber, drumpad->getLightColour() * inputEvent.velocity);
            break;
        }
        case InputSignal::DRUMPAD_HOLD:
        {
            midiSend.setPadRGB(drumpad->padNumber, drumpad->getLightColour() * inputEvent.velocity);
            break;
        }
        case InputSignal::DRUMPAD_UP:
        {
            drumpad->setLightOff();
            midiSend.setPadRGB(drumpad->padNumber, drumpad->getLightColour());
            break;
        }
        default:
        {
            break;
        }
    }
    return StateAction::None;
};

StateAction DefaultState::handleButtonInput(const InputEvent& inputEvent) {
    return StateAction::None;
};
