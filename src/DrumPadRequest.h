#ifndef DRUMPAD_REQUEST
#define DRUMPAD_REQUEST

#include "DrumPad.h"

enum class DrumPadSignal {
    DRUMPAD_DOWN,
    DRUMPAD_HOLD,
    DRUMPAD_UP
};

class DrumPadRequest {
public:
    DrumPad* drumpad = nullptr;
    DrumPadSignal signal;

    DrumPadRequest(DrumPad* drumpad, DrumPadSignal signal) : drumpad(drumpad), signal(signal) {}
};

#endif