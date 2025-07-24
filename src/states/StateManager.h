#ifndef STATE_MANAGER
#define STATE_MANAGER

#include "State.h"
#include "DefaultState.h"
#include "../commands/CommandProcessor.h"
#include "../commands/Command.h"
#include "../input/InputEvent.h"
#include "../audio/AudioController.h"

#include <stack>
#include <memory>

// Forward Declaration
struct MPCContext;

class StateManager {
public:
    MPCContext* mpcContext = nullptr;

    StateManager(CommandProcessor& commandProcessor, AudioController& audio);

    void handleEvent(InputEvent& event);
protected:
    std::stack<State*> stateStack;
    CommandProcessor& commandProcessor;
    DefaultState defaultState;
};

#endif