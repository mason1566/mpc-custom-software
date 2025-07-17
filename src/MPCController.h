#pragma once
#include <libremidi/libremidi.hpp>
#include "AudioController.h"
#include "Input.cpp"
#include <vector>
#include <iomanip>
#include <iostream>

class MPCController {
public:
    libremidi::observer observer;
    std::unique_ptr<libremidi::midi_in> midi_in;
    libremidi::midi_out midi_out;
    std::vector<Button> buttons;
    std::vector<DrumPad> drumpads;
    AudioController audio;

    MPCController();
    void Boot();
    void HandleMidiMessage(libremidi::message message);
protected:


};