#ifndef COMPOSITE_COMMAND
#define COMPOSITE_COMMAND

#include "Command.h"

#include <vector>

class CompositeCommand : public Command {
public:
    void Execute() { for (Command* command : commands) { command->Execute(); } }
protected:
    std::vector<Command*> commands;
};

#endif