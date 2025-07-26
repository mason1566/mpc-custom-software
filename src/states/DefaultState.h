#ifndef DEFAULT_STATE
#define DEFAULT_STATE

#include "State.h"

class DefaultState : protected State {
public:
    std::shared_ptr<Command> handleInput(const InputEvent& inputEvent);
    DefaultState() : State() {}
};

#endif