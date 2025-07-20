#ifndef MIDI_RECEIVER
#define MIDI_RECEIVER

#include "BaseMidi.h"
#include <functional>

// Singleton
class MidiReceiver : protected BaseMidi {
public:
    std::unique_ptr<libremidi::midi_in> midi_in;

    void setMidiCallbackFunction(std::function<void (libremidi::message message)> midiCallbackFunc) { midiCallback = midiCallbackFunc; }

    // Singleton instance function
    static MidiReceiver* Instance();
private:
    MidiReceiver();

    std::function<void (libremidi::message message)> midiCallback = 0;

    static MidiReceiver* _instance;
};

#endif