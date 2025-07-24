#include "SetDrumPadRGBCommand.h"

void SetDrumPadRGBCommand::Execute() {
    midiSend.setPadRGB(padNumber, colour);
}