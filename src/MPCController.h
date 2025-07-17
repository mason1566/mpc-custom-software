#pragma once
#include <libremidi/libremidi.hpp>
#include "Input.cpp"
#include <vector>

class MPCController {
public:
    libremidi::observer observer;
    std::unique_ptr<libremidi::midi_in> midi_in;
    libremidi::midi_out midi_out;
    std::vector<Button> buttons;
    std::vector<DrumPad> drumpads;

    MPCController();
    void Boot();
    void HandleMidiMessage(libremidi::message message);
protected:


};