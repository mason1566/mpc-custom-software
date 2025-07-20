#ifndef MIDI_CONTROLLER
#define MIDI_CONTROLLER

#include <libremidi/libremidi.hpp>
#include <functional>

// Singleton
class MidiController {
public:
    libremidi::observer observer;
    std::unique_ptr<libremidi::midi_in> midi_in;
    libremidi::midi_out midi_out;

    void setMidiCallbackFunction(std::function<void (libremidi::message message)> midiCallbackFunc) { midiCallback = midiCallbackFunc; }

    // Singleton instance function
    static MidiController* Instance();
protected:
    MidiController();

    std::function<void (libremidi::message message)> midiCallback = 0;

    static MidiController* _instance;
};

#endif