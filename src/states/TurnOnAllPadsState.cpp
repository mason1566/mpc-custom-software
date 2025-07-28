#include "TurnOnAllPadsState.h"

StateAction TurnOnAllPadsState::handleInput(const InputEvent& inputEvent) {
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
    // if (inputEvent.inputSignal == InputSignal::DRUMPAD_DOWN || inputEvent.inputSignal == InputSignal::DRUMPAD_HOLD){
    //     // return StateAction::Defer;
    // } 
    // else if (inputEvent.inputSignal == InputSignal::DRUMPAD_UP) {
    //     midiSend.setPadRGB(input.drum_map[inputEvent.midiValue]->padNumber, input.drum_map[inputEvent.midiValue]->getLightColour());
    // }
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
            return StateAction::Pop;
        }
    }
    return StateAction::None;
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

void TurnOnAllPadsState::onEnter() {
    turnOnAllDrumPads();
}

void TurnOnAllPadsState::onExit() {
    turnOffAllDrumPads();
}