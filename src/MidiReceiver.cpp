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
        if (midiCallback != 0) {
            MidiInputSignal midiSignal { (int)message.bytes[0], (int)message.bytes[1], (int)message.bytes[2] };
            midiCallback(midiSignal);
        }
    };

    midi_in = std::make_unique<libremidi::midi_in>(
        libremidi::input_configuration{ .on_message = callback }
    );

    midi_in->open_port(getMidiObserver()->get_input_ports()[0]);
}