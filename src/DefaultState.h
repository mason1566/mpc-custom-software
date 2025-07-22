#ifndef DEFAULT_STATE
#define DEFAULT_STATE

#include "MPCState.h"

class DefaultState : protected MPCState {
public:
    DefaultState(MPC* mpc) : MPCState(mpc) {}
    void handleRequest(DrumPadRequest request);
    void handleRequest(ButtonRequest request);
};

#endif