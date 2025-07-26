#ifndef CONFIGURABLE_COMPOSITE_COMMAND
#define CONFIGURABLE_COMPOSITE_COMMAND

#include "CompositeCommand.h"

class ConfigurableCompositeCommand : public CompositeCommand {
public:
    void pushCommand(std::shared_ptr<Command> command) { commandQueue.push_back(command); }
};

#endif