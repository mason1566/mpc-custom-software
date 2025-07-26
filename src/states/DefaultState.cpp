#include "DefaultState.h"

#include <iostream>

StateAction DefaultState::handleInput(const InputEvent& inputEvent) {
    // Defer input events to their specific handler function
    if (inputEvent.inputType == InputType::DRUMPAD_INPUT) {
        return handleDrumPadInput(inputEvent);
    } else if (inputEvent.inputType == InputType::BUTTON_INPUT) {
        return handleButtonInput(inputEvent);
    }
    return StateAction::None;
};

StateAction DefaultState::handleDrumPadInput(const InputEvent& inputEvent) {
    DrumPad& drumpad = *input.drum_map[inputEvent.midiValue];

    // if (inputEvent.inputSignal == InputSignal::DRUMPAD_DOWN) {
    //     // std::cout << "DrumPad Down!\n";
    //     drumpad.setLightOn();
    //     midiSend.setPadRGB(drumpad.padNumber, drumpad.getLightColour() * inputEvent.velocity);
    // }
    // else if (inputEvent.inputSignal == InputSignal::DRUMPAD_HOLD) {
        // midiSend.setPadRGB(drumpad.padNumber, drumpad.getLightColour() * inputEvent.velocity);
    // }
    // else if (inputEvent.inputSignal == InputSignal::DRUMPAD_UP) {
    //     // std::cout << "DrumPad Up!\n";
    //     drumpad.setLightOff();
    //     midiSend.setPadRGB(drumpad.padNumber, drumpad.getLightColour());
    // }

    switch (inputEvent.inputSignal) 
    {
        case InputSignal::DRUMPAD_DOWN:
        {
            drumpad.setLightOn();
            midiSend.setPadRGB(drumpad.padNumber, drumpad.getLightColour() * inputEvent.velocity);
            break;
        }
        case InputSignal::DRUMPAD_HOLD:
        {
            midiSend.setPadRGB(drumpad.padNumber, drumpad.getLightColour() * inputEvent.velocity);
            break;
        }
        case InputSignal::DRUMPAD_UP:
        {
            drumpad.setLightOff();
            midiSend.setPadRGB(drumpad.padNumber, drumpad.getLightColour());
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
