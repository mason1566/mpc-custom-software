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
    midi = MidiController::Instance();

    midiCallback = [this](libremidi::message message) { HandleMidiMessage(message); };
    midi->setMidiCallbackFunction(midiCallback);
    setupDrumPads();
};

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

    // Add drumpads to the drum_map
    for (int i = 0; i < drumpads.size(); i++) {
        drum_map[drumpads[i].midiCode] = &(drumpads[i]);
    }
}

/* MEMBER FUNCTIONS */
void MPC::Boot() {
    // Set initial colour of drumpads
    for (int i = 0; i < drumpads.size(); i++) {
        drumpads[i].setLightOff();
        SetPadRGB(&(drumpads[i]));
    }

    while (true) {}
};

void MPC::HandleMidiMessage(libremidi::message message) {
    // for (auto byte : message.bytes) {
    //     std::cout << std::hex << std::setw(2) << (int)byte << "(" << std::dec << (int)byte << ")" << " ";
    // }
    // std::cout << std::endl;

    int midiSignal = (int)message.bytes[0];
    int midiCode = (int)message.bytes[1];
    int velocity = (int)message.bytes[2];

    if (midiSignal == MPC_CONSTANTS::MIDI_MESSAGES::DRUMPAD_DOWN) {
        DrumPad* drumpad = drum_map[midiCode];

        if (drumpad) OnDrumPadDown(drumpad);
    }
    else if ((int)message.bytes[0] == MPC_CONSTANTS::MIDI_MESSAGES::DRUMPAD_UP) {
        DrumPad* drumpad = drum_map[midiCode];

        if (drumpad) OnDrumPadUp(drumpad);
    }
};

void MPC::SetPadRGB(DrumPad* pad, RGB colour) {
    // Midi sysex message format for controlling drumpad LED values is as follows:
    // { 
    //      msg_start, mfg_id, dev_id, model_id, msg_type, data_length, data_length_2, 
    //      PAD_NUM, RED_VALUE (0-127), GREEN_VALUE (0-127), BLUE_VALUE (0-127), msg_end 
    // }
    // We are only interested in modifying the PAD_NUM, RED_VALUE, GREEN_VALUE, and BLUE_VALUE.
    
    // Convert colour values into unsigned char. This is because midi_out.send_message expects unsigned char values
    unsigned char padNum = static_cast<unsigned char>(pad->padNumber);
    unsigned char red = static_cast<unsigned char>(colour.getRed());
    unsigned char green = static_cast<unsigned char>(colour.getGreen());
    unsigned char blue = static_cast<unsigned char>(colour.getBlue());

    unsigned char bytes[12] = { 
        0xF0, 0x47, 0x47, 0x4A, 0x65, 0x00, 0x04, 
        padNum, red, green, blue, 0xF7 
    };
    midi->midi_out.send_message(bytes, sizeof(bytes));
};

void MPC::SetPadRGB(DrumPad* pad) {
    unsigned char padNum = static_cast<unsigned char>(pad->padNumber);
    unsigned char red = static_cast<unsigned char>(pad->getLightColour().getRed());
    unsigned char green = static_cast<unsigned char>(pad->getLightColour().getGreen());
    unsigned char blue = static_cast<unsigned char>(pad->getLightColour().getBlue());
    
    // std::cout << (int)padNum << " " << (int)pad->getLightColour().getRed() << " " << (int)green << " " << (int)blue << std::endl;

    unsigned char bytes[12] = { 
        0xF0, 0x47, 0x47, 0x4A, 0x65, 0x00, 0x04, 
        padNum, red, green, blue, 0xF7 
    };
    midi->midi_out.send_message(bytes, sizeof(bytes));
}

void MPC::OnDrumPadDown(DrumPad* drumpad) {
    drumpad->setLightOn();
    SetPadRGB(drumpad, drumpad->getLightColour());

    audio.MakeSound();
}

void MPC::OnDrumPadUp(DrumPad* drumpad) {
    drumpad->setLightOff();
    SetPadRGB(drumpad, drumpad->getLightColour());
}