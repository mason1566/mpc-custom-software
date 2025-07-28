#ifndef DEFAULT_STATE
#define DEFAULT_STATE

#include "State.h"

#include "../midi/MidiSender.h"
#include "../input/InputManager.h"
#include "../audio/AudioController.h"

#include <memory>

class StateManager;

class DefaultState : protected State {
public:
    StateAction handleInput(const InputEvent& inputEvent) override;
    DefaultState(MidiSender& midiSend, InputManager& input, StateManager& stateManager, AudioController& audio) : midiSend(midiSend), input(input), stateManager(stateManager), audio(audio), State() {}

    virtual void onEnter() override {}
    virtual void onExit() override {}
    virtual void onPause() override;
    virtual void onResume() override {}
protected:
    MidiSender& midiSend;
    InputManager& input;
    StateManager& stateManager;
    AudioController& audio;

    DrumPad* activeDrumPad = nullptr;

    StateAction handleDrumPadInput(const InputEvent& inputEvent) override;
    StateAction handleButtonInput(const InputEvent& inputEvent) override;
};

#endif