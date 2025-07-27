#include "TurnOnAllPadsState.h"

StateAction TurnOnAllPadsState::handleInput(const InputEvent& inputEvent) {
    if (!lightsOn) {
        turnOnAllDrumPads();
        lightsOn = true;
    }

    // Defer input events to their specific handler function
    if (inputEvent.inputType == InputType::DRUMPAD_INPUT) {
        return handleDrumPadInput(inputEvent);
    } 
    else if (inputEvent.inputType == InputType::BUTTON_INPUT) {
        return handleButtonInput(inputEvent);
    }
    return StateAction::None;
};

StateAction TurnOnAllPadsState::handleDrumPadInput(const InputEvent& inputEvent) {
    return StateAction::None;
};

StateAction TurnOnAllPadsState::handleButtonInput(const InputEvent& inputEvent) {
    // switch (inputEvent.midiValue) {
        // case MPC_CONSTANTS::BUTTON_MIDI_VALUES::COPY:
        // {
        //     if (inputEvent.inputSignal == InputSignal::BUTTON_DOWN && activeDrumPad) {
        //         State* copyPasteState = (State*) new CopyPasteRGBState(midiSend, input, stateManager, activeDrumPad);
        //         stateManager.pushState(copyPasteState);
        //     }
        // }
    // }
    
    if (inputEvent.inputSignal == InputSignal::BUTTON_UP) {
        if (inputEvent.midiValue == MPC_CONSTANTS::BUTTON_MIDI_VALUES::FULL_LEVEL) {
            turnOffAllDrumPads();
            return StateAction::Pop;
        }
    }
};

void TurnOnAllPadsState::turnOffAllDrumPads() {
    for (DrumPad& drumpad : input.drumpads) {
        drumpad.setLightOff();
        midiSend.setPadRGB(drumpad.padNumber, drumpad.getLightColour());
    }
};

void TurnOnAllPadsState::turnOnAllDrumPads() {
    for (DrumPad& drumpad : input.drumpads) {
        drumpad.setLightOn();
        midiSend.setPadRGB(drumpad.padNumber, drumpad.getLightColour());
    }
};