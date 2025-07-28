#include "DefaultState.h"

#include <iostream>

#include "StateManager.h"
#include "CopyPasteRGBState.h"
#include "TurnOnAllPadsState.h"

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
    DrumPad* drumpad = input.drum_map[inputEvent.midiValue];

    if (!drumpad) return StateAction::Error;
    
    switch (inputEvent.inputSignal) 
    {
        case InputSignal::DRUMPAD_DOWN:
        {
            // std::cout << "Signal DRUMPAD_DOWN from Pad: " << drumpad->padNumber << std::endl;
            activeDrumPad = drumpad;
            drumpad->setLightOn();
            midiSend.setPadRGB(drumpad->padNumber, drumpad->getLightColour() * inputEvent.velocity);
            audio.MakeSound(&drumpad->sound->getSound());
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
    // switch (inputEvent.midiValue) {
    //     case MPC_CONSTANTS::BUTTON_MIDI_VALUES::COPY:
    //     {
    //         if (inputEvent.inputSignal == InputSignal::BUTTON_DOWN && activeDrumPad) {
    //             State* copyPasteState = (State*) new CopyPasteRGBState(midiSend, input, stateManager, activeDrumPad);
    //             stateManager.pushState(copyPasteState);
    //         }
    //     }
    // }
    // switch (inputEvent.inputSignal) {
        // case InputSignal::BUTTON_DOWN:
        // {
        //     if (inputEvent.midiValue == MPC_CONSTANTS::BUTTON_MIDI_VALUES::COPY && activeDrumPad) {
        //         State* copyPasteState = (State*) new CopyPasteRGBState(midiSend, input, stateManager, activeDrumPad);
        //         stateManager.pushState(copyPasteState);
        //     }
        //     else if (inputEvent.midiValue == MPC_CONSTANTS::BUTTON_MIDI_VALUES::FULL_LEVEL) {
        //         State* turnOnPadsState = (State*) new TurnOnAllPadsState(midiSend, input, stateManager);
        //         stateManager.pushState(turnOnPadsState);
        //         turnOnPadsState->handleInput(inputEvent);
        //     }
        // }
        // default:
        // {
        //     break;
        // }
    // }

    if (inputEvent.inputSignal == InputSignal::BUTTON_DOWN) {
        switch (inputEvent.midiValue) {
            case MPC_CONSTANTS::BUTTON_MIDI_VALUES::COPY:
            {
                if (activeDrumPad) {
                    State* copyPasteState = (State*) new CopyPasteRGBState(midiSend, input, stateManager, activeDrumPad);
                    stateManager.pushState(copyPasteState);
                    return StateAction::Push;
                }
                break;
            }
            case MPC_CONSTANTS::BUTTON_MIDI_VALUES::FULL_LEVEL:
            {
                State* turnOnPadsState = (State*) new TurnOnAllPadsState(midiSend, input, stateManager);
                stateManager.pushState(turnOnPadsState);
                return StateAction::Push;
            }
            case MPC_CONSTANTS::BUTTON_MIDI_VALUES::MINUS:
            {
                if (activeDrumPad) {
                    activeDrumPad->sound->goPreviousSoundSet();
                }
                break;
            }
            case MPC_CONSTANTS::BUTTON_MIDI_VALUES::PLUS:
            {
                if (activeDrumPad) {
                    activeDrumPad->sound->goNextSoundSet();
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }
    else if (inputEvent.inputSignal == InputSignal::KNOB_TURN_CLOCKWISE) {
        if (activeDrumPad) {
            activeDrumPad->sound->goNextSound();
        }
    }
    else if (inputEvent.inputSignal == InputSignal::KNOB_TURN_COUNTER_CLOCKWISE) {
        if (activeDrumPad) {
            activeDrumPad->sound->goPreviousSound();
        }
    }

    return StateAction::None;
};

void DefaultState::onPause() {
    activeDrumPad = nullptr;
}