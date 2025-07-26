#ifndef STATE_MANAGER
#define STATE_MANAGER

#include "State.h"
#include "DefaultState.h"
#include "../commands/Command.h"
#include "../input/InputEvent.h"

#include <stack>
#include <memory>

class CommandProcessor;

class StateManager {
public:
    void handleEvent(InputEvent& event);

    static StateManager& instance();
protected:
    std::stack<State*> stateStack;
    DefaultState defaultState;

    StateManager() {};
};

#endif