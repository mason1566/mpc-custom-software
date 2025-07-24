#ifndef COMMAND_PROCESSOR
#define COMMAND_PROCESSOR

#include "Command.h"

#include <vector>

class CommandProcessor {
public:
    void enqueueCommand(Command* command);

    
    CommandProcessor() {}
protected:
    std::vector<Command*> commandQueue;
};

#endif