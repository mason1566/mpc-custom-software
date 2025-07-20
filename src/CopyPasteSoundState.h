#ifndef COPY_PASTE_SOUND_STATE
#define COPY_PASTE_SOUND_STATE

#include "MPCState.h"

class CopyPasteSoundState : public MPCState {
public:

    CopyPasteSoundState(std::string stateName) : MPCState(stateName) {}
};

#endif