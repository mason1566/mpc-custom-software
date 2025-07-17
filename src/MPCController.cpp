#include "MPCController.h"
#include <iostream>

void MPCController::HandleMidiMessage(libremidi::message message) {
    std::cout << "Midi in detected!" << std::endl;
}

MPCController::MPCController() {
    auto callback = [this](libremidi::message&& message) {
        this->HandleMidiMessage(message);
    };

    midi_in = std::make_unique<libremidi::midi_in>(
        libremidi::input_configuration{ .on_message = callback }
    );
};

void MPCController::Boot() {

    // Open midi ports
    midi_in->open_port(observer.get_input_ports()[0]);
    midi_out.open_port(observer.get_output_ports()[0]);

    while (true) {}
};

