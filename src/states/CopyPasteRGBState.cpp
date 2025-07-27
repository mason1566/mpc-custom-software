#include "CopyPasteRGBState.h"

#include <iostream>

StateAction CopyPasteRGBState::handleInput(const InputEvent& inputEvent) {
    State::handleInput(inputEvent);
    return StateAction::None;
};

StateAction CopyPasteRGBState::handleDrumPadInput(const InputEvent& inputEvent) {
    DrumPad* drumpad = input.drum_map[inputEvent.midiValue];
    std::cout << "CopyPasteRGBState says hi.\n";
    // switch (inputEvent.inputSignal) 
    // {
    //     case InputSignal::DRUMPAD_DOWN:
    //     {
    //         if (!drumpad1) {
    //             drumpad1 = drumpad;
    //         }
    //         drumpad->setLightOn();
    //         midiSend.setPadRGB(drumpad->padNumber, drumpad->getLightColour() * inputEvent.velocity);
    //         break;
    //     }
    //     case InputSignal::DRUMPAD_HOLD:
    //     {
    //         midiSend.setPadRGB(drumpad->padNumber, drumpad->getLightColour() * inputEvent.velocity);
    //         break;
    //     }
    //     case InputSignal::DRUMPAD_UP:
    //     {
    //         drumpad->setLightOff();
    //         midiSend.setPadRGB(drumpad->padNumber, drumpad->getLightColour());
    //         break;
    //     }
    //     default:
    //     {
    //         break;
    //     }
    // }
    return StateAction::None;
};

StateAction CopyPasteRGBState::handleButtonInput(const InputEvent& inputEvent) {
    return StateAction::None;
};
