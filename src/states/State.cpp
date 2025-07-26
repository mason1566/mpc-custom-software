#include "State.h"

StateAction State::handleInput(const InputEvent& inputEvent) {
    // Defer input events to their specific handler function
    if (inputEvent.inputType == InputType::DRUMPAD_INPUT) {
        return handleDrumPadInput(inputEvent);
    } else if (inputEvent.inputType == InputType::BUTTON_INPUT) {
        return handleButtonInput(inputEvent);
    }
    return StateAction::None;
}