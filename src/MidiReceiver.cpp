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
            int signalCode { (int)message.bytes[0] };
            int midiValue { (int)message.bytes[1] };
            int velocity { (int)message.bytes[2] };
            
            switch (signalCode) 
            {
            case MIDI_INPUT_SIGNALS::DRUMPAD_DOWN:
                midiCallback(MidiInputSignal { signalCode, midiValue, velocity, InputType::DRUMPAD_INPUT, InputSignal::DRUMPAD_DOWN } );
            case MIDI_INPUT_SIGNALS::DRUMPAD_HOLD:
                midiCallback(MidiInputSignal { signalCode, midiValue, velocity, InputType::DRUMPAD_INPUT, InputSignal::DRUMPAD_HOLD } );
            case MIDI_INPUT_SIGNALS::DRUMPAD_UP:
                midiCallback(MidiInputSignal { signalCode, midiValue, velocity, InputType::DRUMPAD_INPUT, InputSignal::DRUMPAD_UP } );
            case MIDI_INPUT_SIGNALS::BUTTON_DOWN:
                midiCallback(MidiInputSignal { signalCode, midiValue, velocity, InputType::BUTTON_INPUT, InputSignal::BUTTON_DOWN } );
            case MIDI_INPUT_SIGNALS::BUTTON_UP:
                midiCallback(MidiInputSignal { signalCode, midiValue, velocity, InputType::BUTTON_INPUT, InputSignal::BUTTON_UP } );
            default:
                break;
            }
        }
    };

    midi_in = std::make_unique<libremidi::midi_in>(
        libremidi::input_configuration{ .on_message = callback }
    );

    midi_in->open_port(getMidiObserver()->get_input_ports()[0]);
}