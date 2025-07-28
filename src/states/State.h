#ifndef MPC_STATE
#define MPC_STATE

#include "../input/InputEvent.h"
#include "../input/InputManager.h"

#include <memory>

enum class StateAction { None, Pop, Error, Defer, Push /*, Clear */};

class State {
public:
    virtual StateAction handleInput(const InputEvent& inputEvent);
    virtual ~State() = default;

    virtual void onEnter() = 0;        // Called when state becomes active
    virtual void onExit() = 0;        // Called when state is popped
    virtual void onPause() = 0;       // Optional: state under another
    virtual void onResume() = 0;      // Optional: state back on top
protected:
    virtual StateAction handleDrumPadInput(const InputEvent& inputEvent) = 0;
    virtual StateAction handleButtonInput(const InputEvent& inputEvent) = 0;
};

#endif