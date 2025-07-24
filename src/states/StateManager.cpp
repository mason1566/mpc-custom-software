#include "StateManager.h"

#include "../MPCContext.h"

#include <iostream>

StateManager::StateManager(CommandProcessor& commandProcessor, AudioController& audio) : commandProcessor(commandProcessor), defaultState(audio) {}

void StateManager::handleEvent(InputEvent& event) {
    // std::cout << "Hello from StateManager!\n";

    // If the stateStack is empty, defer handling to the default state
    if (stateStack.size() == 0) {
        Command* stateCommand = defaultState.handleInput(event);
        
        // If a command is present, push it to the commandProcessor queue
        if (stateCommand) {
            commandProcessor.enqueueCommand(stateCommand);
        }
    }

}