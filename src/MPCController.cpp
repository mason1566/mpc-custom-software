#include "MPCController.h"

/* SINGLETON INSTANCE IMPLEMENTATION */
MPCController* MPCController::_instance = nullptr;

MPCController* MPCController::Instance() {
    if (!_instance) 
        _instance = new MPCController;
    return _instance;
}

/* CONSTRUCTOR */
MPCController::MPCController() {
    // Create lambda expression callback function for midi message handling
    auto callback = [this](libremidi::message&& message) {
        this->HandleMidiMessage(message);
    };

    midi_in = std::make_unique<libremidi::midi_in>(
        libremidi::input_configuration{ .on_message = callback }
    );

    // Add a drumpad object for each preset drumpad id code
    // int padNumber = 0;

    // for (int id_code : MPC_CONSTANTS::DRUMPAD_IDENTIFIERS) {
    //     DrumPad drumpad { id_code, padNumber };
    //     drumpads.push_back(drumpad);
    //     input_map[id_code] = (Input*) &drumpads.back();
    //     padNumber++;
    // }

    // for (int i = 0; i < MPC_CONSTANTS::DRUMPAD_COUNT; i++) {
    //     drumpads.push_back(DrumPad{ MPC_CONSTANTS::DRUMPAD_IDENTIFIERS[i], i });
    //     drum_map[drumpads[i].midiCode] = &drumpads[i];
    // }

    setupDrumPads();
};

void MPCController::setupDrumPads() {
    drumpads.push_back(DrumPad { 37, 0});
    drumpads.push_back(DrumPad { 36, 1});
    drumpads.push_back(DrumPad { 42, 2});
    drumpads.push_back(DrumPad { 82, 3});
    drumpads.push_back(DrumPad { 40, 4});
    drumpads.push_back(DrumPad { 38, 5});
    drumpads.push_back(DrumPad { 46, 6});
    drumpads.push_back(DrumPad { 44, 7});
    drumpads.push_back(DrumPad { 48, 8});
    drumpads.push_back(DrumPad { 47, 9});
    drumpads.push_back(DrumPad { 45, 10});
    drumpads.push_back(DrumPad { 43, 11});
    drumpads.push_back(DrumPad { 49, 12});
    drumpads.push_back(DrumPad { 55, 13});
    drumpads.push_back(DrumPad { 51, 14});
    drumpads.push_back(DrumPad { 53, 15});

}

/* MEMBER FUNCTIONS */
void MPCController::Boot() {

    // Open midi ports
    midi_in->open_port(observer.get_input_ports()[0]);
    midi_out.open_port(observer.get_output_ports()[0]);

    // Set initial colour of drumpads
    float percent = 0;
    float step = 1.0 / 16.0; 
    for (DrumPad pad : drumpads) {
        int fade = 127 * percent;
        SetPadRGB(&pad, RGB(127, fade, fade));
        percent += step;
    }

    while (true) {}
};

void MPCController::HandleMidiMessage(libremidi::message message) {
    // for (auto byte : message.bytes) {
    //     std::cout << std::hex << std::setw(2) << (int)byte << "(" << std::dec << (int)byte << ")" << " ";
    // }
    // std::cout << std::endl;

    if ((int)message.bytes[0] == MPC_CONSTANTS::MIDI_MESSAGES::DRUMPAD_DOWN) {
        // int inputCode = (int)message.bytes[1];
        // Input input = *input_map[inputCode];
        // DrumPad* drumpad = dynamic_cast<DrumPad*>(drumpad);

        // if (drumpad) {

        // }
    }

    // int inputCode = message.bytes[1];
    // std::cout << input_map[inputCode]->idCode << std::endl;
};

void MPCController::SetPadRGB(DrumPad* pad, RGB colour) {
    pad->setLightColour(colour);

    std::cout << pad->midiCode << " " << pad->padNumber << std::endl;

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
    midi_out.send_message(bytes, sizeof(bytes));
};