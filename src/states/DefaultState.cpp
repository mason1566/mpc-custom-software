#include "DefaultState.h"

#include <iostream>

#include "StateManager.h"
#include "CopyPasteRGBState.h"

StateAction DefaultState::handleInput(const InputEvent& inputEvent) {
    State::handleInput(inputEvent);
    return StateAction::None;
};

StateAction DefaultState::handleDrumPadInput(const InputEvent& inputEvent) {
    DrumPad* drumpad = input.drum_map[inputEvent.midiValue];

    if (!drumpad) return StateAction::Error;
    
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
    switch (inputEvent.midiValue) {
        case MPC_CONSTANTS::BUTTON_MIDI_VALUES::COPY:
        {
            State* copyPasteState = (State*) new CopyPasteRGBState(midiSend, input);
            stateManager.pushState(copyPasteState);
        }
    }
    return StateAction::None;
};
