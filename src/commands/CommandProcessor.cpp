#include "CommandProcessor.h"

void CommandProcessor::enqueueCommand(Command* command) {
    commandQueue.push(command);
};

void CommandProcessor::tick() {
    if (commandQueue.size() > 0) {
        Command* command = commandQueue.front();
        commandQueue.pop(); // remove the command from the queue

        // Execute the command
        command->Execute();
        delete command;
        command = nullptr;
    }
};