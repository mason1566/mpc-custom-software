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

            if (signalCode == MPC_CONSTANTS::MIDI_MESSAGES::DRUMPAD_DOWN || signalCode == MPC_CONSTANTS::MIDI_MESSAGES::DRUMPAD_HOLD || signalCode == MPC_CONSTANTS::MIDI_MESSAGES::DRUMPAD_UP) 
            {
                MidiInputSignal midiSignal { signalCode, midiValue, velocity, MidiInputType::DRUMPAD_INPUT  };
                midiCallback(midiSignal);
            }
            else if (signalCode == MPC_CONSTANTS::MIDI_MESSAGES::BUTTON_DOWN || signalCode == MPC_CONSTANTS::MIDI_MESSAGES::BUTTON_UP) 
            {
                MidiInputSignal midiSignal { signalCode, midiValue, velocity, MidiInputType::BUTTON_INPUT  };
                midiCallback(midiSignal);
            }



        }
    };

    midi_in = std::make_unique<libremidi::midi_in>(
        libremidi::input_configuration{ .on_message = callback }
    );

    midi_in->open_port(getMidiObserver()->get_input_ports()[0]);
}