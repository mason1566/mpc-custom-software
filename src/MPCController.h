#ifndef MPC_CONTROLLER
#define MPC_CONTROLLER

#include <libremidi/libremidi.hpp>
#include "AudioController.h"
#include "Input.h"
#include "Utility.h"
#include <vector>
#include <iomanip>
#include <iostream>
#include <unordered_map>

class MPCController {
public:
    libremidi::observer observer;
    std::unique_ptr<libremidi::midi_in> midi_in;
    libremidi::midi_out midi_out;
    std::vector<Button> buttons;
    std::vector<DrumPad> drumpads;
    AudioController audio;
    std::unordered_map<int, Input*> input_map;

    MPCController();
    void Boot();
    void HandleMidiMessage(libremidi::message message);
protected:


};

#endif