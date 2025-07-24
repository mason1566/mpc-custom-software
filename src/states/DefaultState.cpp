#include "DefaultState.h"
#include <iostream>

Command* DefaultState::handleInput(const InputEvent& inputEvent) {
    // std::cout << "Hello!" << std::endl;
    Command* makeSound = (Command*)(new MakeSoundCommand(audio));

    return makeSound;
}; 
