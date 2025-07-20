#ifndef MPC_STATE
#define MPC_STATE

#include "Utility.h"
#include <string>

class MPCState {
public:
    std::string name;

    MPCState(std::string stateName) : name(stateName) {}
    // virtual void 
};

#endif