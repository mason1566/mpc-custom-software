#include "DefaultState.h"

#include <iostream>

void DefaultState::handleInput(const InputEvent& inputEvent) {
    if (inputEvent.inputType == InputType::DRUMPAD_INPUT) {
        DrumPad& drumpad = *input.drum_map[inputEvent.midiValue];

        if (inputEvent.inputSignal == InputSignal::DRUMPAD_DOWN) {
            // std::cout << "DrumPad Down!\n";
            drumpad.setLightOn();
            midiSend.setPadRGB(drumpad.padNumber, drumpad.getLightColour());
        }
        else if (inputEvent.inputSignal == InputSignal::DRUMPAD_HOLD) {
            RGB newColour { inputEvent.velocity, inputEvent.velocity, inputEvent.velocity };

            midiSend.setPadRGB(drumpad.padNumber, newColour);
        }
        else if (inputEvent.inputSignal == InputSignal::DRUMPAD_UP) {
            // std::cout << "DrumPad Up!\n";
            drumpad.setLightOff();
            midiSend.setPadRGB(drumpad.padNumber, drumpad.getLightColour());
        }
    }
}; 
