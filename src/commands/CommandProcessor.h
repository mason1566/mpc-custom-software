#ifndef COMMAND_PROCESSOR
#define COMMAND_PROCESSOR

#include "Command.h"

#include <queue>
#include <memory>

// Forward declaration
class InputManager;

// Singleton
class CommandProcessor {
public:
    void enqueueCommand(std::shared_ptr<Command> command);
    void tick();
    
    static CommandProcessor& instance();
protected:
    std::queue<std::shared_ptr<Command>> commandQueue;
    InputManager& input;

    CommandProcessor();
};

#endif