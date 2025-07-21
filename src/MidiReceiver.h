#ifndef MIDI_RECEIVER
#define MIDI_RECEIVER

#include "BaseMidi.h"
#include "MidiInputSignal.h"
#include <functional>

// Singleton
class MidiReceiver : protected BaseMidi {
public:
    std::unique_ptr<libremidi::midi_in> midi_in;

    void setMidiCallbackFunction(std::function<void (MidiInputSignal)> midiCallbackFunc) { midiCallback = midiCallbackFunc; }

    // Singleton instance function
    static MidiReceiver* Instance();
private:
    MidiReceiver();

    std::function<void (MidiInputSignal)> midiCallback = 0;

    static MidiReceiver* _instance;
};

#endif