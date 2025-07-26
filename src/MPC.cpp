#include "MPC.h"

/* SINGLETON INSTANCE IMPLEMENTATION */
MPC* MPC::_instance = nullptr;

MPC* MPC::Instance() {
    if (!_instance) 
        _instance = new MPC;
    return _instance;
}

/* CONSTRUCTOR */
MPC::MPC() 
  : midiSend(MidiSender::instance()), 
    midiReceive(MidiReceiver::instance()),
    audio(AudioController::instance()),
    inputManager(),
    stateManager(audio, midiSend, inputManager)
{
    midiReceive.setMidiCallbackFunction([&](const libremidi::message& message) {
        inputManager.handleMidiMessage(message);
    });

    inputManager.setInputEventCallback([&](const InputEvent& inputEvent) {
        stateManager.handleEvent(inputEvent);
    });

    // Turn on Pad Mute Button light
    // unsigned char message[] { MPC_CONSTANTS::MIDI_MESSAGES::MIDI_CONTROL_CHANGE, 4, 3 };
    // midi->midi_out.send_message(message, sizeof(message));
};

/* MEMBER FUNCTIONS */
void MPC::Boot() {
    while (true) {
        stateManager.tick();
    }
};