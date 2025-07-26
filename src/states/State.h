#ifndef MPC_STATE
#define MPC_STATE

#include "../input/InputEvent.h"
#include "../input/InputManager.h"

#include <memory>

class State {
public:
    virtual void handleInput(const InputEvent& inputEvent) = 0;
    virtual ~State() = default;
};

#endif