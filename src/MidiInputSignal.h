#ifndef MIDI_INPUT_SIGNAL
#define MIDI_INPUT_SIGNAL

enum class MidiInputType {
    DRUMPAD_INPUT, BUTTON_INPUT
};

class MidiInputSignal {
public:
    int signalCode;
    int midiValue;
    int velocity;
    MidiInputType inputType;

    MidiInputSignal(int signalCode, int midiValue, int velocity, MidiInputType inputType) : signalCode(signalCode), midiValue(midiValue), velocity(velocity), inputType(inputType) {}
};

#endif