#include "StateManager.h"

#include <iostream>

#include "../commands/CommandProcessor.h"

StateManager& StateManager::instance() {
    static StateManager instance;
    return instance;
};

void StateManager::handleEvent(InputEvent& event) {
    // std::cout << "Hello from StateManager!\n";

    // If the stateStack is empty, defer handling to the default state
    if (stateStack.size() == 0) {
        std::shared_ptr<Command> command = defaultState.handleInput(event);
        
        // If a command is present, push it to the commandProcessor queue
        if (command) {
            CommandProcessor::instance().enqueueCommand(command);
        }
    }

}