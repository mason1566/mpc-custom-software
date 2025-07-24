#ifndef STATE_MANAGER
#define STATE_MANAGER

#include "State.h"
#include "DefaultState.h"
#include "../commands/CommandProcessor.h"
#include "../input/InputEvent.h"

#include <stack>

// Forward Declaration
struct MPCContext;

class StateManager {
public:
    MPCContext* mpcContext = nullptr;

    StateManager(CommandProcessor& commandProcessor) : commandProcessor(commandProcessor) {}

    void handleEvent(InputEvent& event);
protected:
    std::stack<State*> stateStack;
    CommandProcessor& commandProcessor;
    DefaultState defaultState;
};

#endif