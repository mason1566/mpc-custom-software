#ifndef MIDI_CONTROLLER
#define MIDI_CONTROLLER

#include <libremidi/libremidi.hpp>

// Singleton
class MidiController {
public:
    static MidiController* Instance();
protected:
    static MidiController* _instance;
    
    libremidi::observer observer;
    std::unique_ptr<libremidi::midi_in> midi_in;
    libremidi::midi_out midi_out;

    MidiController();
    void HandleMidiMessage(libremidi::message message);
};

#endif