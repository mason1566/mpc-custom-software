#ifndef COMPOSITE_COMMAND
#define COMPOSITE_COMMAND

#include "Command.h"

#include <vector>
#include <memory>

class CompositeCommand : public Command {
public:
    virtual void Execute() { for (std::shared_ptr<Command> command : commandQueue) { command->Execute(); } }
protected:
    std::vector<std::shared_ptr<Command>> commandQueue;
};

#endif