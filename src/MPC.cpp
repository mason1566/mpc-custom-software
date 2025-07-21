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

    // Turn on Pad Mute Button light
    // unsigned char message[] { MPC_CONSTANTS::MIDI_MESSAGES::MIDI_CONTROL_CHANGE, 4, 3 };
    // midi->midi_out.send_message(message, sizeof(message));
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

    // Add drumpads to input_map and drum_map
    for (int i = 0; i < drumpads.size(); i++) {
        drum_map[drumpads[i].midiCode] = &(drumpads[i]);
        input_map[drumpads[i].midiCode] = &(drumpads[i]);
    }
}

/* MEMBER FUNCTIONS */
void MPC::Boot() {

    // Open midi ports


    // Set initial colour of drumpads
    for (int i = 0; i < drumpads.size(); i++) {
        drumpads[i].setLightOff();
        midi_send->setPadRGB(i, drumpads[i].getLightColour());
    }

    while (true) {}
};

void MPC::HandleMidiMessage(libremidi::message message) {
    for (auto byte : message.bytes) {
        std::cout << std::hex << std::setw(2) << (int)byte << "(" << std::dec << (int)byte << ")" << " ";
    }
    std::cout << std::endl;

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

    // int inputCode = message.bytes[1];
    // std::cout << input_map[inputCode]->idCode << std::endl;
};

void MPC::OnDrumPadDown(DrumPad* drumpad) {
    drumpad->setLightOn();
    midi_send->setPadRGB(drumpad->padNumber, drumpad->getLightColour());

    audio.MakeSound();
}

void MPC::OnDrumPadUp(DrumPad* drumpad) {
    drumpad->setLightOff();
    midi_send->setPadRGB(drumpad->padNumber, drumpad->getLightColour());
}