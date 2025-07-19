#include "MidiController.h"
// #include <iostream>
// #include <iomanip>

/* SINGLETON INSTANCE IMPLEMENTATION */
MidiController* MidiController::_instance = nullptr;

MidiController* MidiController::Instance() {
    if (!_instance)
        _instance = new MidiController;
    return _instance;
};

/* CONSTRUCTOR */
MidiController::MidiController() {
    auto callback = [this](libremidi::message&& message) {
        this->HandleMidiMessage(message);
    };

    midi_in = std::make_unique<libremidi::midi_in>(
        libremidi::input_configuration{ .on_message = callback }
    );

    // Open midi ports
    midi_in->open_port(observer.get_input_ports()[0]);
    midi_out.open_port(observer.get_output_ports()[0]);
}

void MidiController::HandleMidiMessage(libremidi::message message) {
    // for (auto byte : message.bytes) {
    //     std::cout << std::hex << std::setw(2) << (int)byte << "(" << std::dec << (int)byte << ")" << " ";
    // }
    // std::cout << std::endl;
}