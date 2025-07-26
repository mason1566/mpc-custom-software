#ifndef MAKE_SOUND_COMMAND
#define MAKE_SOUND_COMMAND

#include "Command.h"
#include "../audio/AudioController.h"

class MakeSoundCommand : public Command {
public:
    void Execute();
    MakeSoundCommand() {}
};

#endif