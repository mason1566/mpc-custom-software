#ifndef COPY_PASTE_SOUND_STATE
#define COPY_PASTE_SOUND_STATE

#include "MPCState.h"
#include "DrumPad.h"

class CopyPasteSoundState : protected MPCState {
public:
    DrumPad* drumpad1 = nullptr;
    DrumPad* drumpad2 = nullptr;

    CopyPasteSoundState(MPC* mpc) : MPCState(mpc) {}
    void handleRequest(DrumPadRequest request);
    void handleRequest(ButtonRequest request);
protected:
    // DrumPad input handlers
    void handleDrumPadDown(DrumPad* drumpad);
    void handleDrumPadHold(DrumPad* drumpad);
    void handleDrumPadUp(DrumPad* drumpad);

    // Button input handlers
    void handleButtonDown(Button* button);
    void handleButtonUp(Button* button);

    void performCopyPaste();
};

#endif