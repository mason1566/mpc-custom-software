#ifndef MPC_CONTROLLER
#define MPC_CONTROLLER

#include <libremidi/libremidi.hpp>

#include "AudioController.h"
#include "Input.h"
#include "Utility.h"
#include "RGB.h"

#include <vector>
#include <iomanip>
#include <iostream>
#include <unordered_map>

// Singleton
class MPCController {
public:
    libremidi::observer observer;
    std::unique_ptr<libremidi::midi_in> midi_in;
    libremidi::midi_out midi_out;
    std::vector<Button> buttons;
    std::vector<DrumPad> drumpads;
    AudioController audio;
    std::unordered_map<int, Input*> input_map;

    void Boot();
    void HandleMidiMessage(libremidi::message message);
    void SetPadRGB(DrumPad* pad, RGB colour);

    // Singleton Instance function. This is the accessor to the shared MPCController instance
    static MPCController* Instance();
protected:
    // Protected constructor for singleton pattern
    MPCController();

    // Common MPCController Instance variable
    static MPCController* _instance;
};

#endif