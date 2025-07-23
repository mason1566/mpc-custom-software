#ifndef DRUMPAD_REQUEST
#define DRUMPAD_REQUEST

#include "DrumPad.h"
#include "MidiInputSignal.h"

class DrumPadRequest {
public:
    DrumPad* drumpad = nullptr;
    MidiInputSignal inputSignal;

    DrumPadRequest(DrumPad* drumpad, MidiInputSignal inputSignal) : drumpad(drumpad), inputSignal(inputSignal) {}
};

#endif