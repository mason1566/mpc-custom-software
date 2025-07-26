#ifndef MPC_STATE
#define MPC_STATE

#include "../commands/Command.h"
#include "../input/InputEvent.h"

#include <memory>

class State {
public:
    virtual std::shared_ptr<Command> handleInput(const InputEvent& inputEvent) = 0;
    virtual ~State() = default;
};

#endif