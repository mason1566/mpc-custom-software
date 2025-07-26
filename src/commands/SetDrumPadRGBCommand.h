#ifndef SET_DRUMPAD_RGB_COMMAND
#define SET_DRUMPAD_RGB_COMMAND

#include "Command.h"
#include "../midi/MidiSender.h"
#include "../utility/RGB.h"

class SetDrumPadRGBCommand : public Command {
public:
    void Execute();
    SetDrumPadRGBCommand(int padNumber, RGB colour) : padNumber(padNumber), colour(colour) {}
protected:
    int padNumber;
    RGB colour;
};

#endif