#ifndef DEFAULT_STATE
#define DEFAULT_STATE

#include "State.h"

class DefaultState : public State {
public:
    Command* handleInput(const InputEvent& inputEvent, MPCContext& context);
    DefaultState(AudioController& audio) : audio(audio) {}
protected:
    AudioController& audio;
};

#endif