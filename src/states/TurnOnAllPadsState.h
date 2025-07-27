#ifndef TURN_ON_ALL_PADS_STATE
#define TURN_ON_ALL_PADS_STATE

#include "State.h"

#include "../midi/MidiSender.h"
#include "../input/InputManager.h"
#include "StateManager.h"

class TurnOnAllPadsState : protected State {
public:
    StateAction handleInput(const InputEvent& inputEvent) override;
    TurnOnAllPadsState(MidiSender& midiSend, InputManager& input, StateManager& stateManager) : midiSend(midiSend), input(input), stateManager(stateManager), State() {}
protected:
    MidiSender& midiSend;
    InputManager& input;
    StateManager& stateManager;

    void turnOnAllDrumPads();
    void turnOffAllDrumPads();

    bool lightsOn = false;

    StateAction handleDrumPadInput(const InputEvent& inputEvent) override;
    StateAction handleButtonInput(const InputEvent& inputEvent) override;
};

#endif