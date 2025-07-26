#ifndef MPC_CONTROLLER
#define MPC_CONTROLLER

#include <libremidi/libremidi.hpp>

#include "midi/MidiSender.h"
#include "midi/MidiReceiver.h"
#include "audio/AudioController.h"
#include "states/StateManager.h"
#include "input/InputManager.h"

#include <vector>
#include <memory>
#include <iomanip>
#include <iostream>

// Singleton
// MPC is simply a Coordinator between the objects. 
// MPC wires up connections via callback functions and lets the objects handle the rest
class MPC {
public:
    MidiSender& midiSend;
    MidiReceiver& midiReceive;
    AudioController& audio;
    StateManager stateManager;
    InputManager inputManager;


    void Boot();

    // Singleton Instance function. This is the accessor to the shared MPCController instance
    static MPC* Instance();
protected:
    // Protected constructor for singleton pattern
    MPC();

    // Common MPCController Instance variable
    static MPC* _instance;
};

#endif