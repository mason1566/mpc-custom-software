#include "StateManager.h"

#include <iostream>

void StateManager::handleEvent(const InputEvent& event) {
    // std::cout << "Hello from StateManager!\n";

    // If the stateStack is empty, defer handling to the default state
    // if (stateStack.empty()) {
    //     // std::cout << "State Stack is Empty!\n";
    //     defaultState.handleInput(event);
    // }
    std::lock_guard<std::mutex> lock(mutex);
    eventQueue.push(event);
};
    
void StateManager::tick() {
    if (!eventQueue.empty()) {
        const InputEvent& event = eventQueue.front();
        eventQueue.pop();

        StateAction stateResponse;

        // Determine which state should handle the input event
        if (stateStack.empty()) {
            stateResponse = defaultState.handleInput(event);
        }
        else {
            stateResponse = stateStack.top()->handleInput(event);
        }

        // Respond to request from state
        if (stateResponse == StateAction::Pop) {
            if (!stateStack.empty()) {
                State* state = stateStack.top();
                stateStack.pop();
                delete state;
            }
        }
    }
};