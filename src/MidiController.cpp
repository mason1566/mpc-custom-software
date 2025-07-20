#include "MidiController.h"

// Singleton Instance
MidiController* MidiController::_instance = nullptr;

MidiController* MidiController::Instance() {
    if (!_instance) 
        _instance = new MidiController;
    return _instance;
}

// Constructor
MidiController::MidiController() {
    // Create lambda expression callback function for midi message handling
    auto callback = [this](libremidi::message&& message) {
        // this->HandleMidiMessage(message);
        if (midiCallback != 0)
            midiCallback(message);
    };

    midi_in = std::make_unique<libremidi::midi_in>(
        libremidi::input_configuration{ .on_message = callback }
    );

    midi_in->open_port(observer.get_input_ports()[0]);
    midi_out.open_port(observer.get_output_ports()[0]);
}
