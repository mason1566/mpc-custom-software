#ifndef MPC_CONTROLLER
#define MPC_CONTROLLER

#include <libremidi/libremidi.hpp>

#include "MidiSender.h"
#include "MidiReceiver.h"
#include "AudioController.h"
#include "BaseInput.h"
#include "DrumPad.h"
#include "Button.h"
#include "Utility.h"
#include "RGB.h"
#include "MidiInputSignal.h"

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
    std::unordered_map<int, BaseInput*> input_map;
    std::unordered_map<int, Button*> button_map;
    std::unordered_map<int, DrumPad*> drum_map;
    DrumPad* currentDrumpad = nullptr;

    void Boot();
    void HandleMidiMessage(MidiInputSignal midiSignal);

    // Singleton Instance function. This is the accessor to the shared MPCController instance
    static MPC* Instance();
protected:
    // Protected constructor for singleton pattern
    MPC();

    // Button Member Functions
    void setupButtons();
    void OnButtonDown(Button* button);
    void OnButtonUp(Button* button);

    // DrumPad Member Functions
    void setupDrumPads();
    void OnDrumPadDown(DrumPad* drumpad);
    void OnDrumPadHold(DrumPad* drumpad);
    void OnDrumPadUp(DrumPad* drumpad);

    // Common MPCController Instance variable
    static MPC* _instance;
};

#endif