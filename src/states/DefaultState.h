#ifndef DEFAULT_STATE
#define DEFAULT_STATE

#include "State.h"

#include "../midi/MidiSender.h"
#include "../input/InputManager.h"

class StateManager;

class DefaultState : protected State {
public:
    StateAction handleInput(const InputEvent& inputEvent) override;
    DefaultState(MidiSender& midiSend, InputManager& input, StateManager& stateManager) : midiSend(midiSend), input(input), stateManager(stateManager), State() {}
protected:
    MidiSender& midiSend;
    InputManager& input;
    StateManager& stateManager;

    DrumPad* activeDrumPad = nullptr;

    StateAction handleDrumPadInput(const InputEvent& inputEvent) override;
    StateAction handleButtonInput(const InputEvent& inputEvent) override;
};

#endif