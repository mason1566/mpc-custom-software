#ifndef MPC_STATE
#define MPC_STATE

#include "../DrumPadRequest.h"
#include "../ButtonRequest.h"

class MPCState {
public:
    MPCState() {}
    void handleRequest(DrumPadRequest request);
    void handleRequest(ButtonRequest request);
protected:

    // DrumPad input handlers
    virtual void handleDrumPadDown(DrumPad* drumpad) = 0;
    virtual void handleDrumPadHold(DrumPad* drumpad) = 0;
    virtual void handleDrumPadUp(DrumPad* drumpad) = 0;

    // Button input handlers
    virtual void handleButtonDown(Button* button) = 0;
    virtual void handleButtonUp(Button* button) = 0;
};

#endif