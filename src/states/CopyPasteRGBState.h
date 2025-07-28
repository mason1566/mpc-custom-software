#ifndef COPY_PASTE_RGB_STATE
#define COPY_PASTE_RGB_STATE

#include "State.h"

#include "../midi/MidiSender.h"
#include "../input/InputManager.h"
#include "StateManager.h"

class CopyPasteRGBState : protected State {
public:
    StateAction handleInput(const InputEvent& inputEvent) override;
    CopyPasteRGBState(MidiSender& midiSend, InputManager& input, StateManager& stateManager, DrumPad* copyPad);

    virtual void onEnter() override {}
    virtual void onExit() override {}
    virtual void onPause() override {}
    virtual void onResume() override {}
protected:
    MidiSender& midiSend;
    InputManager& input;
    StateManager& stateManager;

    DrumPad* copyPad = nullptr;

    StateAction handleDrumPadInput(const InputEvent& inputEvent) override;
    StateAction handleButtonInput(const InputEvent& inputEvent) override;
};

#endif