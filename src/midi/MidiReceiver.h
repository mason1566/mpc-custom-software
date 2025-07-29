#ifndef MIDI_RECEIVER
#define MIDI_RECEIVER

#include "BaseMidi.h"
#include "../utility/Utility.h"
#include "../events/EventDispatcher.h"
#include "../events/MPCEvents.h"

#include <functional>

// Singleton
// Holds a callback: "std::function<void(const MidiMessage&)> onMessage;""
// Called when MIDI is received.
class MidiReceiver : protected BaseMidi {
public:
    std::unique_ptr<libremidi::midi_in> midi_in;

    // Singleton instance function
    static MidiReceiver& instance();
private:
    MidiReceiver();
};

#endif