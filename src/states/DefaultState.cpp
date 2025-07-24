#include "DefaultState.h"
#include <iostream>

#include "../commands/ConfigurableCompositeCommand.h"
#include "../commands/SetDrumPadRGBCommand.h"


Command* DefaultState::handleInput(const InputEvent& inputEvent, MPCContext& context) {
    // std::cout << "Hello!" << std::endl;
    SetDrumPadRGBCommand* setRGB = new SetDrumPadRGBCommand { context.midiSend, 0, RGB::BLUE };

    return (Command*)setRGB;
}; 
