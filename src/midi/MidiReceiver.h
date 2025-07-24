#ifndef MIDI_RECEIVER
#define MIDI_RECEIVER

#include "BaseMidi.h"
#include "../utility/Utility.h"
#include <functional>

// Singleton
// Holds a callback: "std::function<void(const MidiMessage&)> onMessage;""
// Called when MIDI is received.
class MidiReceiver : protected BaseMidi {
public:
    std::unique_ptr<libremidi::midi_in> midi_in;

    void setMidiCallbackFunction(std::function<void (const libremidi::message&)> midiCallbackFunc) { midiCallback = midiCallbackFunc; }

    // Singleton instance function
    static MidiReceiver* Instance();
private:
    MidiReceiver();

    std::function<void (const libremidi::message&)> midiCallback = 0;

    static MidiReceiver* _instance;
};

#endif