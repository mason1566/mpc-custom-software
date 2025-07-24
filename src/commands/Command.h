#ifndef MPC_COMMAND
#define MPC_COMMAND

// forward declaration for MPC class
class MPC;

class Command {
public:
    virtual void Execute();
    virtual void Undo();
};

#endif