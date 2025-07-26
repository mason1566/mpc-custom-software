#ifndef MPC_COMMAND
#define MPC_COMMAND

class Command {
public:
    virtual void Execute() = 0;
    // virtual void Undo();
    Command() {}
    virtual ~Command() = default;
};

#endif