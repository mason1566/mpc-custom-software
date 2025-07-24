#ifndef DEFAULT_STATE
#define DEFAULT_STATE

#include "State.h"

class DefaultState : public State {
public:
    std::unique_ptr<Command> handleInput(const InputEvent& inputEvent);
};

#endif