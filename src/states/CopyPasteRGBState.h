#ifndef COPY_PASTE_RGB_STATE
#define COPY_PASTE_RGB_STATE

#include "State.h"

#include "../midi/MidiSender.h"
#include "../input/InputManager.h"

class CopyPasteRGBState : protected State {
public:
    StateAction handleInput(const InputEvent& inputEvent) override;
    CopyPasteRGBState(MidiSender& midiSend, InputManager& input) : midiSend(midiSend), input(input), State() {}
protected:
    MidiSender& midiSend;
    InputManager& input;

    DrumPad* drumpad1 = nullptr;
    DrumPad* drumpad2 = nullptr;

    StateAction handleDrumPadInput(const InputEvent& inputEvent) override;
    StateAction handleButtonInput(const InputEvent& inputEvent) override;
};

#endif