#ifndef MPC_CONTROLLER
#define MPC_CONTROLLER

#include <libremidi/libremidi.hpp>

#include "MidiSender.h"
#include "MidiReceiver.h"
#include "AudioController.h"
#include "Input.h"
#include "DrumPad.h"
#include "Button.h"
#include "Utility.h"
#include "RGB.h"

#include <vector>
#include <iomanip>
#include <iostream>
#include <unordered_map>

// Singleton
class MPC {
public:
    MidiSender* midi_send = nullptr;
    MidiReceiver* midi_receive = nullptr;
    std::vector<Button> buttons;
    std::vector<DrumPad> drumpads;
    AudioController audio;
    // std::unordered_map<int, Input*> input_map;
    std::unordered_map<int, DrumPad*> drum_map;

    void Boot();
    void HandleMidiMessage(libremidi::message message);
    void SetPadRGB(DrumPad* pad, RGB colour);
    void SetPadRGB(DrumPad* pad);

    // Singleton Instance function. This is the accessor to the shared MPCController instance
    static MPC* Instance();
protected:
    // Protected constructor for singleton pattern
    MPC();

    // DrumPad Member Functions
    void setupDrumPads();
    void OnDrumPadDown(DrumPad* drumpad);
    void OnDrumPadUp(DrumPad* drumpad);


    std::function<void (libremidi::message message)> midiCallback;

    // Common MPCController Instance variable
    static MPC* _instance;
};

#endif