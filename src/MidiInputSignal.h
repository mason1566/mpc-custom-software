#ifndef MIDI_INPUT_SIGNAL
#define MIDI_INPUT_SIGNAL

#include "Utility.h"

class MidiInputSignal {
public:
    int signalCode;
    int midiValue;
    int velocity;
    InputType inputType;
    InputSignal inputSignal;

    MidiInputSignal(int signalCode, int midiValue, int velocity, InputType inputType, InputSignal inputSignal) : signalCode(signalCode), midiValue(midiValue), velocity(velocity), inputType(inputType), inputSignal(inputSignal) {}
};

#endif