#ifndef CONFIGURABLE_COMPOSITE_COMMAND
#define CONFIGURABLE_COMPOSITE_COMMAND

#include "CompositeCommand.h"

class ConfigurableCompositeCommand : public CompositeCommand {
public:
    void pushCommand(Command* command) { commands.push_back(command); }
};

#endif