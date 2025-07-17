#include "MPCController.h"

void MPCController::HandleMidiMessage(libremidi::message message) {
    // for (auto digit : message.bytes) {
    //     std::cout << std::hex << std::setw(2) << (int)digit << "(" << std::dec << (int)digit << ")" << " ";
    // }
    // std::cout << std::endl;

    int inputCode = message.bytes[1];
    std::cout << input_map[inputCode]->idCode << std::endl;
};

MPCController::MPCController() {
    auto callback = [this](libremidi::message&& message) {
        this->HandleMidiMessage(message);
    };

    midi_in = std::make_unique<libremidi::midi_in>(
        libremidi::input_configuration{ .on_message = callback }
    );

    // Add a drumpad object for each preset drumpad id code
    for (int id_code : MPC_CONSTANTS::DRUMPAD_IDENTIFIERS) {
        DrumPad drumpad { id_code };
        drumpads.push_back(drumpad);
        input_map[id_code] = (Input*) &drumpads.back();
    }
};

void MPCController::Boot() {

    // Open midi ports
    midi_in->open_port(observer.get_input_ports()[0]);
    midi_out.open_port(observer.get_output_ports()[0]);

    while (true) {}
};

