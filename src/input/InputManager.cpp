#include "InputManager.h"

// #include <iostream>

InputManager::InputManager() {   
    setupDrumPads();
    setupButtons();
}

int InputManager::getDrumPadNumber(int midiNote) {
    DrumPad* drumpad = drum_map[midiNote];
    if (drumpad) 
        return drumpad->padNumber;
    return INVALID_IDENTIFIER;
}


void InputManager::handleMidiMessage(const libremidi::message& message) {
    // std::cout << "Input Detected in InputManager!\n";
    int signalCode { (int)message.bytes[0] };
    int midiValue { (int)message.bytes[1] };
    int velocity { (int)message.bytes[2] };
    InputType inputType;
    InputSignal inputSignal;

    bool recognizedInput { true };

    switch (signalCode) 
    {
    // DRUMPAD INPUT
        case MIDI_INPUT_SIGNALS::DRUMPAD_DOWN:
            inputType = InputType::DRUMPAD_INPUT;
            inputSignal = InputSignal::DRUMPAD_DOWN;
            break;
        case MIDI_INPUT_SIGNALS::DRUMPAD_HOLD:
            inputType = InputType::DRUMPAD_INPUT;
            inputSignal = InputSignal::DRUMPAD_HOLD;
            break;
        case MIDI_INPUT_SIGNALS::DRUMPAD_UP:
            inputType = InputType::DRUMPAD_INPUT;
            inputSignal = InputSignal::DRUMPAD_UP;
            break;

    // BUTTON INPUT
        case MIDI_INPUT_SIGNALS::BUTTON_DOWN:
            inputType = InputType::BUTTON_INPUT;
            inputSignal = InputSignal::BUTTON_DOWN;
            break;
        case MIDI_INPUT_SIGNALS::BUTTON_UP:
            inputType = InputType::BUTTON_INPUT;
            inputSignal = InputSignal::BUTTON_UP;
            break;
        case MIDI_INPUT_SIGNALS::KNOB_TURN:
            // std::cout << "KNOB INPUT!\n";
            inputType = InputType::BUTTON_INPUT;
            if (midiValue == MPC_CONSTANTS::BUTTON_MIDI_VALUES::KNOB && velocity == MIDI_INPUT_SIGNALS::KNOB_TURN_CLOCKWISE_VELOCITY)
                inputSignal = InputSignal::KNOB_TURN_CLOCKWISE;
            else if (midiValue == MPC_CONSTANTS::BUTTON_MIDI_VALUES::KNOB && velocity == MIDI_INPUT_SIGNALS::KNOB_TURN_COUNTER_CLOCKWISE_VELOCITY)
                inputSignal = InputSignal::KNOB_TURN_COUNTER_CLOCKWISE;
            else
                inputSignal = InputSignal::ERROR;
            break;
    
    // UNRECOGNIZED INPUT
        default:
            recognizedInput = false;
            break;
    }

    // If the input is recognized, delegate the input event information to the State Manager.
    if (recognizedInput && inputCallback) {
        InputEvent inputEvent { signalCode, midiValue, velocity, inputType, inputSignal };
        inputCallback(inputEvent); // Delegate responsibility to the stateManager object
    }

}

/* DRUMPADS */
void InputManager::setupDrumPads() {
    // add drumpads to the vector
    for (int i = 0; i < MPC_CONSTANTS::DRUMPAD_COUNT; i++) {
        drumpads.push_back( DrumPad { MPC_CONSTANTS::DRUMPAD_MIDI_VALUES[i], i } );
    }

    // Set initial colour of drumpads
    float percent = 0;
    float step = 1.0 / 16.0; 
    for (int i = 0; i < drumpads.size(); i++) {
        int fade = 127 * percent;
        RGB padColour = RGB ( 127, fade, fade );
        drumpads[i].setLightColour(padColour);
        percent += step;
    }

    // Add drumpads to input_map and drum_map
    for (int i = 0; i < drumpads.size(); i++) {
        drum_map[drumpads[i].midiValue] = &(drumpads[i]);
        input_map[drumpads[i].midiValue] = &(drumpads[i]);
    }
}

/* BUTTONS */
void InputManager::setupButtons() {
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::TOUCH_STRIP_BUTTON });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::PAD_MUTE });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::ERASE });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::NOTE_REPEAT });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::QUANTIZE });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::TRACK_SELECT });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::PROGRAM_SELECT });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::TC_ON_OFF });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::SAMPLE_START });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::SAMPLE_END });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::PAD_BANK_AE });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::PAD_BANK_BF });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::PAD_BANK_CG });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::PAD_BANK_DH });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::FULL_LEVEL });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::SIXTEEN_LEVEL });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::SAMPLE_SELECT });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::SHIFT });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::BROWSE });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::MAIN });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::TAP_TEMPO });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::PLUS });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::MINUS });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::ZOOM });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::UNDO });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::LEFT });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::RIGHT });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::LOCATE });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::LEFT_LEFT });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::RIGHT_RIGHT });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::RECORD });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::AUTOMATION_READ_WRITE });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::TUNE });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::OVERDUB });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::STOP });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::PLAY });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::PLAY_START });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::JOG_WHEEL });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::MODE });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::COPY });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::KNOB });
    buttons.push_back(Button { MPC_CONSTANTS::BUTTON_MIDI_VALUES::KNOB_BUTTON });

    // Add drumpads to input_map and drum_map
    for (int i = 0; i < buttons.size(); i++) {
        button_map[buttons[i].midiValue] = &(buttons[i]);
        input_map[buttons[i].midiValue] = &(buttons[i]);
    }
}

void InputManager::setupDrumPadSounds(std::vector<SoundSet>& soundSets) {
    int defaultLibrarySize = soundSets[0].size();
    for (int i = 0; i < drumpads.size(); i++) {
        if (i < defaultLibrarySize) {
            drumpads[i].sound = std::make_unique<DrumPadSound>(soundSets, 0, i);
        }
    }
};