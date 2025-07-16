#pragma once
#include <libremidi/libremidi.hpp>

class MPCController {
public:
    libremidi::observer observer;
    std::unique_ptr<libremidi::midi_in> midi_in;
    libremidi::midi_out midi_out;

    MPCController();
    void Boot();
    void HandleMidiMessage(libremidi::message message);
protected:


};