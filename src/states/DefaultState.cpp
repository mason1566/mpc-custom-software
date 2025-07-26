#include "DefaultState.h"
#include <iostream>

#include "../commands/ConfigurableCompositeCommand.h"
#include "../commands/SetDrumPadRGBCommand.h"
#include "../commands/MakeSoundCommand.h"
#include "../input/InputManager.h"


std::shared_ptr<Command> DefaultState::handleInput(const InputEvent& inputEvent) {
    if (inputEvent.inputType == InputType::DRUMPAD_INPUT) {
        if (inputEvent.inputSignal == InputSignal::DRUMPAD_DOWN) {
            DrumPad& drumpad = *input.drum_map[inputEvent.midiValue];
            drumpad.setLightOn();
            std::shared_ptr<ConfigurableCompositeCommand> commands = std::make_shared<ConfigurableCompositeCommand>();
            commands->pushCommand(std::make_shared<SetDrumPadRGBCommand>(drumpad.padNumber, drumpad.getLightColour()));
            commands->pushCommand(std::make_shared<MakeSoundCommand>());
            // std::shared_ptr<Command> command = std::make_shared<SetDrumPadRGBCommand>(drumpad.padNumber, drumpad.getLightColour());
            return commands;
        }
        else if (inputEvent.inputSignal == InputSignal::DRUMPAD_UP) {
            DrumPad& drumpad = *input.drum_map[inputEvent.midiValue];
            drumpad.setLightOff();
            std::shared_ptr<Command> command = std::make_shared<SetDrumPadRGBCommand>(drumpad.padNumber, drumpad.getLightColour());
            return command;
        }
    }

    return nullptr;
}; 
