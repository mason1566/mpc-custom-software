#ifndef STATE_MANAGER
#define STATE_MANAGER

#include "State.h"
#include "DefaultState.h"
#include "../input/InputEvent.h"

#include "../midi/MidiSender.h"
#include "../audio/AudioController.h"
#include "../input/InputManager.h"

#include <stack>
#include <queue>
#include <memory>
#include <mutex>
#include <thread>


class StateManager {
public:
    void handleEvent(const InputEvent& event);
    void tick();

    StateManager(AudioController& audio, MidiSender& midiSend, InputManager& input) : audio(audio), midiSend(midiSend), input(input), defaultState(midiSend, input, *this), eventQueue() {}
protected:
    std::stack<State*> stateStack;
    DefaultState defaultState;

    std::queue<InputEvent> eventQueue;

    bool statePopQueued = false;
    std::mutex mutex;

    // System references
    AudioController& audio;
    MidiSender& midiSend;
    InputManager& input;
};

#endif