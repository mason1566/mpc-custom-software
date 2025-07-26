#ifndef COMPOSITE_COMMAND
#define COMPOSITE_COMMAND

#include "Command.h"

#include <queue>
#include <memory>

class CompositeCommand : public Command {
// public:
//     void Execute() { for (Command* command : commands) { command->Execute(); } }
//     CompositeCommand(MPCContext& context) : Command(context) {}
//     ~CompositeCommand() { 
//         // Delete all the commands in the commands vector
//         while (commands.size() > 0) {
//             Command* command = commands.back();
//             commands.pop_back();
//             delete command;
//         }
//     }
// protected:
//     std::vector<Command*> commands;
public:
    void Execute();

protected:
    std::queue<std::shared_ptr<Command>> commandQueue;
};

#endif