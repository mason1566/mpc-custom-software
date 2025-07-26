#ifndef STATE_MANAGER
#define STATE_MANAGER

#include "State.h"
#include "DefaultState.h"
#include "../input/InputEvent.h"

#include "../midi/MidiSender.h"
#include "../audio/AudioController.h"
#include "../input/InputManager.h"

#include <stack>
#include <memory>


class StateManager {
public:
    void handleEvent(const InputEvent& event);

    StateManager(AudioController& audio, MidiSender& midiSend, InputManager& input) : audio(audio), midiSend(midiSend), input(input), defaultState(midiSend, input) {}
protected:
    std::stack<State*> stateStack;
    DefaultState defaultState;
    AudioController& audio;
    MidiSender& midiSend;
    InputManager& input;
};

#endif