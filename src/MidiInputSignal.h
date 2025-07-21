#ifndef MIDI_INPUT_SIGNAL
#define MIDI_INPUT_SIGNAL

class MidiInputSignal {
public:
    int signalCode;
    int midiValue;
    int velocity;

    MidiInputSignal(int signalCode, int midiValue, int velocity) : signalCode(signalCode), midiValue(midiValue), velocity(velocity) {}
};

#endif