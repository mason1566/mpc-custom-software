#include "CommandProcessor.h"

// #include <iostream>
#include "../input/InputManager.h"

CommandProcessor& CommandProcessor::instance() {
    static CommandProcessor instance;
    return instance;
};

CommandProcessor::CommandProcessor() : input(InputManager::instance()) {}

void CommandProcessor::enqueueCommand(std::shared_ptr<Command> command) {
    commandQueue.push(command);
};

void CommandProcessor::tick() {
    if (commandQueue.size() > 0) {
        std::shared_ptr<Command> command = commandQueue.front();
        commandQueue.pop();
        command->Execute();
        // std::cout << "Command Queue Size: " << commandQueue.size() << std::endl;
    }
};