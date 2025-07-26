#include "StateManager.h"

#include <iostream>

void StateManager::handleEvent(const InputEvent& event) {
    // std::cout << "Hello from StateManager!\n";

    // If the stateStack is empty, defer handling to the default state
    if (stateStack.empty()) {
        // std::cout << "State Stack is Empty!\n";
        defaultState.handleInput(event);
    }

}