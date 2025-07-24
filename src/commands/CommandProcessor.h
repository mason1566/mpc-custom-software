#ifndef COMMAND_PROCESSOR
#define COMMAND_PROCESSOR

#include "Command.h"

#include <queue>

class CommandProcessor {
public:
    void enqueueCommand(Command* command);
    void tick();

    
    CommandProcessor() {}
protected:
    std::queue<Command*> commandQueue;
};

#endif