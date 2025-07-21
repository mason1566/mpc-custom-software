#include "MPC.h"

/* SINGLETON INSTANCE IMPLEMENTATION */
MPC* MPC::_instance = nullptr;

MPC* MPC::Instance() {
    if (!_instance) 
        _instance = new MPC;
    return _instance;
}

/* CONSTRUCTOR */
MPC::MPC() {
    midi_send = MidiSender::Instance();
    midi_receive = MidiReceiver::Instance();

    midiCallback = [this](libremidi::message message) { HandleMidiMessage(message); };
    midi_receive->setMidiCallbackFunction(midiCallback);
    setupDrumPads();
    setupButtons();

    // Turn on Pad Mute Button light
    // unsigned char message[] { MPC_CONSTANTS::MIDI_MESSAGES::MIDI_CONTROL_CHANGE, 4, 3 };
    // midi->midi_out.send_message(message, sizeof(message));
};

/* MEMBER FUNCTIONS */
void MPC::Boot() {
    // Set initial colour of drumpads
    for (int i = 0; i < drumpads.size(); i++) {
        drumpads[i].setLightOff();
        midi_send->setPadRGB(i, drumpads[i].getLightColour());
    }

    while (true) {}
};

void MPC::HandleMidiMessage(libremidi::message message) {
    // for (auto byte : message.bytes) {
    //     std::cout << std::hex << std::setw(2) << (int)byte << "(" << std::dec << (int)byte << ")" << " ";
    // }
    // std::cout << std::endl;

    int signalCode = (int)message.bytes[0];
    int midiValue = (int)message.bytes[1];
    int velocity = (int)message.bytes[2];

    if (signalCode == MPC_CONSTANTS::MIDI_MESSAGES::DRUMPAD_DOWN) {
        DrumPad* drumpad = drum_map[midiValue];

        if (drumpad) OnDrumPadDown(drumpad);
    }
    else if (signalCode == MPC_CONSTANTS::MIDI_MESSAGES::DRUMPAD_UP) {
        DrumPad* drumpad = drum_map[midiValue];

        if (drumpad) OnDrumPadUp(drumpad);
    }
    else if (signalCode == MPC_CONSTANTS::MIDI_MESSAGES::BUTTON_DOWN) {
        Button* button = button_map[midiValue];

        if (button) OnButtonDown(button);
    }

    // int inputCode = message.bytes[1];
    // std::cout << input_map[inputCode]->idCode << std::endl;
};

/* DRUMPADS */
void MPC::setupDrumPads() {
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
        drum_map[drumpads[i].midiCode] = &(drumpads[i]);
        input_map[drumpads[i].midiCode] = &(drumpads[i]);
    }
}

void MPC::OnDrumPadDown(DrumPad* drumpad) {
    drumpad->setLightOn();
    midi_send->setPadRGB(drumpad->padNumber, drumpad->getLightColour());

    audio.MakeSound();
}

void MPC::OnDrumPadHold(DrumPad* drumpad) {}

void MPC::OnDrumPadUp(DrumPad* drumpad) {
    drumpad->setLightOff();
    midi_send->setPadRGB(drumpad->padNumber, drumpad->getLightColour());
}

/* BUTTONS */
void MPC::setupButtons() {
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

    // Add drumpads to input_map and drum_map
    for (int i = 0; i < buttons.size(); i++) {
        button_map[buttons[i].midiCode] = &(buttons[i]);
        input_map[buttons[i].midiCode] = &(buttons[i]);
    }
}

void MPC::OnButtonDown(Button* button) {
    // std::cout << "Button Down!\n";
}