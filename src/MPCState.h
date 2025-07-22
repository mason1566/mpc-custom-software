#ifndef MPC_STATE
#define MPC_STATE

#include "DrumPadRequest.h"
#include "ButtonRequest.h"

// Forward declaration for class MPC
class MPC;

class MPCState {
public:
    MPCState(MPC* mpc) : mpc(mpc) {}
    virtual void handleRequest(DrumPadRequest request) = 0;
    virtual void handleRequest(ButtonRequest request) = 0;
protected:
    MPC* mpc;
};

#endif