#ifndef DEFAULT_STATE
#define DEFAULT_STATE

#include "State.h"
#include "../commands/MakeSoundCommand.h"
#include "../audio/AudioController.h"

class DefaultState : public State {
public:
    Command* handleInput(const InputEvent& inputEvent);
    DefaultState(AudioController& audio) : audio(audio) {}
protected:
    AudioController& audio;
};

#endif