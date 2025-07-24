#include "DefaultState.h"
#include <iostream>

std::unique_ptr<Command> DefaultState::handleInput(const InputEvent& inputEvent) {
    std::cout << "Hello!" << std::endl;
    return nullptr;
}; 
