#ifndef MPC_COMMAND
#define MPC_COMMAND

// forward declaration for MPC class
class MPC;

class MPCCommand {
public:
    virtual void Execute();
    virtual void Undo();

    MPCCommand(MPC* mpc) : mpc(mpc) {}
protected:
    MPC* mpc = nullptr;
};

#endif