#ifndef DEFAULT_STATE
#define DEFAULT_STATE

#include "State.h"

#include "../midi/MidiSender.h"
#include "../input/InputManager.h"

class DefaultState : protected State {
public:
    StateAction handleInput(const InputEvent& inputEvent) override;
    DefaultState(MidiSender& midiSend, InputManager& input) : midiSend(midiSend), input(input), State() {}
protected:
    MidiSender& midiSend;
    InputManager& input;

    StateAction handleDrumPadInput(const InputEvent& inputEvent) override;
    StateAction handleButtonInput(const InputEvent& inputEvent) override;
};

#endif