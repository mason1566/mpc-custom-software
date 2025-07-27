#ifndef MPC_STATE
#define MPC_STATE

#include "../input/InputEvent.h"
#include "../input/InputManager.h"

#include <memory>

enum class StateAction { None, Pop, Error /* , Push, Clear */};

class State {
public:
    virtual StateAction handleInput(const InputEvent& inputEvent);
    virtual ~State() = default;
protected:
    virtual StateAction handleDrumPadInput(const InputEvent& inputEvent) = 0;
    virtual StateAction handleButtonInput(const InputEvent& inputEvent) = 0;
};

#endif