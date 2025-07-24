#ifndef MPC_STATE
#define MPC_STATE

#include "../commands/Command.h"
#include "../input/InputEvent.h"

#include <memory> // for unique_ptr

class State {
public:
    virtual Command* handleInput(const InputEvent& inputEvent) = 0;
    virtual ~State() = default;
};

#endif