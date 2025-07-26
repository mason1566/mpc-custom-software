#include "SetDrumPadRGBCommand.h"

void SetDrumPadRGBCommand::Execute() {
    // context.midiSend.setPadRGB(1, colour);
    // context.midiSend.setPadRGB(padNumber, colour);
    MidiSender& midiSend = MidiSender::instance();
    midiSend.setPadRGB(padNumber, colour);
}