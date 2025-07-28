#include "StateManager.h"

#include <iostream>

void StateManager::handleEvent(const InputEvent& event) {
    // std::cout << "Hello from StateManager!\n";

    // If the stateStack is empty, defer handling to the default state
    // if (stateStack.empty()) {
    //     // std::cout << "State Stack is Empty!\n";
    //     defaultState.handleInput(event);
    // }
    std::lock_guard<std::mutex> lock(eventMutex);
    eventQueue.push(event);
};

void StateManager::pushState(State* state) {
    std::lock_guard<std::mutex> lock(statePushMutex);
    statePushQueue.push(state); // Queue the state to be pushed
};
    
void StateManager::tick() {
    std::lock_guard<std::mutex> lock(tickMutex);
    if (!eventQueue.empty()) {
        const InputEvent event = eventQueue.front();
        eventQueue.pop();

        // { stateStack.push(state); }

        StateAction stateResponse;

        // Determine which state should handle the input event
        if (stateStack.empty()) {
            stateResponse = defaultState.handleInput(event);
        }
        else {
            stateResponse = stateStack.top()->handleInput(event);

            // if (stateResponse == StateAction::Defer) {
            //     stateResponse = defaultState.handleInput(event);
            // }
        }

        // Respond to request from state
        switch (stateResponse) {
            case StateAction::None:
            case StateAction::Defer:
            case StateAction::Error:
            default:
            {
                break;
            }
            case StateAction::Pop:
            {
                // On pop, we need to call the onExit function of the popped state.
                // We also need to call the onResume function of the now in-control state.
                if (!stateStack.empty()) {
                    State* state = stateStack.top();
                    stateStack.pop();

                    state->onExit();
                    delete state;

                    // Call the onResume function of the now in-control state
                    if (!stateStack.empty())
                        stateStack.top()->onResume();
                    else
                        defaultState.onResume();
                }
                break;
            }
            case StateAction::Push:
            {
                if (!statePushQueue.empty()) {
                    // We need to call the onPause function of the currently in-control state
                    if (!stateStack.empty()) 
                        stateStack.top()->onPause();
                    else
                        defaultState.onPause();

                    // Transfer the state first in the queue into the active state stack
                    stateStack.push(statePushQueue.front());
                    statePushQueue.pop();

                    // Call the onEnter function of the new state
                    stateStack.top()->onEnter();
                }
                break;
            }
        };

        // if (stateResponse == StateAction::Pop) {
        //     if (!stateStack.empty()) {
        //         State* state = stateStack.top();
        //         stateStack.pop();
        //         delete state;
        //     }
        // }
    }
};