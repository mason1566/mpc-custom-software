#ifndef DEFAULT_STATE
#define DEFAULT_STATE

#include "State.h"

#include "../midi/MidiSender.h"
#include "../input/InputManager.h"

class DefaultState : protected State {
public:
    void handleInput(const InputEvent& inputEvent);
    DefaultState(MidiSender& midiSend, InputManager& input) : midiSend(midiSend), input(input) {}
protected:
    MidiSender& midiSend;
    InputManager& input;
};

#endif