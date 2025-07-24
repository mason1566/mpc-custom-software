#ifndef SET_DRUMPAD_RGB_COMMAND
#define SET_DRUMPAD_RGB_COMMAND

#include "Command.h"
#include "../midi/MidiSender.h"
#include "../utility/RGB.h"
#include "../input/DrumPad.h"

class SetDrumPadRGBCommand : public Command {
public:
    void Execute();
    SetDrumPadRGBCommand(MidiSender& midiSend, int padNumber, RGB colour) : midiSend(midiSend), padNumber(padNumber), colour(colour) {}
    // SetDrumPadRGBCommand(MidiSender& midiSend, DrumPad& drumpad) : midiSend(midiSend),  drumpad(drumpad), colour(drumpad.getLightColour()) {}
protected:
    MidiSender& midiSend;
    int padNumber;
    RGB colour;
};

#endif