#ifndef CONFIGURABLE_COMPOSITE_COMMAND
#define CONFIGURABLE_COMPOSITE_COMMAND

#include "CompositeCommand.h"

class ConfigurableCompositeCommand : public CompositeCommand {
public:
    // void pushCommand(Command* command) { commands.push_back(command); }
    // ConfigurableCompositeCommand(MPCContext& context) : CompositeCommand(context) {}
    // ~ConfigurableCompositeCommand() { 
    //     // Delete all the commands in the commands vector
    //     while (commands.size() > 0) {
    //         Command* command = commands.back();
    //         commands.pop_back();
    //         delete command;
    //     }
    // }
};

#endif