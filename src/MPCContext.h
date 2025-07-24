#ifndef MPC_CONTEXT
#define MPC_CONTEXT

#include "audio/AudioController.h"
#include "commands/CommandProcessor.h"
#include "midi/MidiReceiver.h"
#include "midi/MidiSender.h"
#include "input/InputManager.h"
#include "states/StateManager.h"

struct MPCContext {
    AudioController& audio;
    CommandProcessor& commandProcessor;
    MidiReceiver& midiReceive;
    MidiSender& midiSend;
    InputManager& inputManager;
    StateManager& stateManager;

    MPCContext(
        AudioController& audio,
        CommandProcessor& commandProcessor,
        MidiReceiver& midiReceive,
        MidiSender& midiSend,
        InputManager& inputManager,
        StateManager& stateManager
    ) : audio(audio), commandProcessor(commandProcessor), midiReceive(midiReceive), midiSend(midiSend), inputManager(inputManager), stateManager(stateManager) {}
};

#endif