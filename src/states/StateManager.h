#ifndef STATE_MANAGER
#define STATE_MANAGER

#include "State.h"
#include "DefaultState.h"
#include "../input/InputEvent.h"
#include "../events/EventDispatcher.h"
#include "../events/MPCEvents.h"
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
    void pushState(State* state);

    StateManager(AudioController& audio, MidiSender& midiSend, InputManager& input);
protected:
    std::stack<State*> stateStack;
    DefaultState defaultState;

    std::queue<State*> statePushQueue;

    std::queue<InputEvent> eventQueue;

    bool statePopQueued = false;
    std::mutex eventMutex;
    std::mutex tickMutex;
    std::mutex statePushMutex;

    // System references
    AudioController& audio;
    MidiSender& midiSend;
    InputManager& input;
};

#endif