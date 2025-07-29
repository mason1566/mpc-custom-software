#include "CopyPasteRGBState.h"

#include <iostream>

CopyPasteRGBState::CopyPasteRGBState(
    MidiSender& midiSend, 
    InputManager& input, 
    StateManager& stateManager, 
    DrumPad* copyPad
) 
    : midiSend(midiSend), input(input), stateManager(stateManager), copyPad(copyPad), State() 
{
    copyPad->setLightOn();
    midiSend.setPadRGB(copyPad->padNumber, copyPad->getLightColour());
}

StateAction CopyPasteRGBState::handleInput(const InputEvent& inputEvent) {
    // Defer input events to their specific handler function
    if (inputEvent.inputType == InputType::DRUMPAD_INPUT) {
        return handleDrumPadInput(inputEvent);
    } else if (inputEvent.inputType == InputType::BUTTON_INPUT) {
        return handleButtonInput(inputEvent);
    }
    return StateAction::None;
};

StateAction CopyPasteRGBState::handleDrumPadInput(const InputEvent& inputEvent) {
    DrumPad* drumpad = input.drum_map[inputEvent.midiValue];
    if (inputEvent.inputSignal == InputSignal::DRUMPAD_DOWN) {
        if (copyPad != drumpad) {
            // Turn on pastePad
            drumpad->setLightColour(copyPad->getLightColour(true));
            drumpad->setLightOn();
            midiSend.setPadRGB(drumpad->padNumber, drumpad->getLightColour());
            
            // Turn off copyPad
            copyPad->setLightOff();
            midiSend.setPadRGB(copyPad->padNumber, copyPad->getLightColour());
        }
        return StateAction::Pop;
    }
    return StateAction::None;
};

StateAction CopyPasteRGBState::handleButtonInput(const InputEvent& inputEvent) {
    if (inputEvent.inputSignal == InputSignal::BUTTON_DOWN) {
        // Turn off copyPad
        copyPad->setLightOff();
        midiSend.setPadRGB(copyPad->padNumber, copyPad->getLightColour());
        
        return StateAction::Pop;
    }
    return StateAction::None;
};
