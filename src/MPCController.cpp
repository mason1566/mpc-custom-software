#include "MPCController.h"

/* CONSTRUCTOR */
MPCController::MPCController() {
    auto callback = [this](libremidi::message&& message) {
        this->HandleMidiMessage(message);
    };

    midi_in = std::make_unique<libremidi::midi_in>(
        libremidi::input_configuration{ .on_message = callback }
    );

    // Add a drumpad object for each preset drumpad id code
    int padNumber = 0;

    for (int id_code : MPC_CONSTANTS::DRUMPAD_IDENTIFIERS) {
        DrumPad drumpad { id_code, padNumber };
        drumpads.push_back(drumpad);
        input_map[id_code] = (Input*) &drumpads.back();
        padNumber++;
    }
};

/* MEMBER FUNCTIONS */
void MPCController::Boot() {

    // Open midi ports
    midi_in->open_port(observer.get_input_ports()[0]);
    midi_out.open_port(observer.get_output_ports()[0]);

    while (true) {}
};

void MPCController::HandleMidiMessage(libremidi::message message) {
    for (auto digit : message.bytes) {
        std::cout << std::hex << std::setw(2) << (int)digit << "(" << std::dec << (int)digit << ")" << " ";
    }
    std::cout << std::endl;

    // int inputCode = message.bytes[1];
    // std::cout << input_map[inputCode]->idCode << std::endl;
};

void MPCController::SetPadRGB(DrumPad* pad, RGB colour) {
    // Midi sysex message format for controlling drumpad LED values is as follows:
    // { 
    //      msg_start, mfg_id, dev_id, model_id, msg_type, data_length, data_length_2, 
    //      PAD_NUM, RED_VALUE (0-127), GREEN_VALUE (0-127), BLUE_VALUE (0-127), msg_end 
    // }
    // We are only interested in the PAD_NUM, RED_VALUE, GREEN_VALUE, and BLUE_VALUE.

};