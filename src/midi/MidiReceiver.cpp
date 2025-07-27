#include "MidiReceiver.h"

// #include <iostream>

MidiReceiver& MidiReceiver::instance() {
    static MidiReceiver instance;
    return instance;
}

MidiReceiver::MidiReceiver() {
    // Create lambda expression callback function for midi message handling
    auto callback = [this](libremidi::message&& message) {
        // std::cout << (int)message.bytes[0] << " " << (int)message.bytes[1] << " " << (int)message.bytes[2] << std::endl;
        if (midiCallback)
            midiCallback(message);
    };

    midi_in = std::make_unique<libremidi::midi_in>(
        libremidi::input_configuration{ .on_message = callback }
    );

    midi_in->open_port(getMidiObserver().get_input_ports()[0]);
}