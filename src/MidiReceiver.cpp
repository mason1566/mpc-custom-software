#include "MidiReceiver.h"

MidiReceiver* MidiReceiver::_instance = nullptr;

MidiReceiver* MidiReceiver::Instance() {
    if (!_instance)
        _instance = new MidiReceiver;
    return _instance;
}

MidiReceiver::MidiReceiver() {
    // Create lambda expression callback function for midi message handling
    auto callback = [this](libremidi::message&& message) {
        // this->HandleMidiMessage(message);
        if (midiCallback != 0)
            midiCallback(message);
    };

    midi_in = std::make_unique<libremidi::midi_in>(
        libremidi::input_configuration{ .on_message = callback }
    );

    midi_in->open_port(getMidiObserver()->get_input_ports()[0]);
}