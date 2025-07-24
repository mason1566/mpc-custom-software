#ifndef INPUT_EVENT
#define INPUT_EVENT

#include "../utility/Utility.h"

class InputEvent {
public:
    int signalCode;
    int midiValue;
    int velocity;
    InputType inputType;
    InputSignal inputSignal;

    InputEvent(int signalCode, int midiValue, int velocity, InputType inputType, InputSignal inputSignal) : signalCode(signalCode), midiValue(midiValue), velocity(velocity), inputType(inputType), inputSignal(inputSignal) {}
};

#endif