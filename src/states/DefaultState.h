#ifndef DEFAULT_STATE
#define DEFAULT_STATE

#include "MPCState.h"

class DefaultState : protected MPCState {
public:
    DefaultState() : MPCState() {}
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
};

#endif