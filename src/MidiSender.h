#ifndef MIDI_SENDER
#define MIDI_SENDER

#include "BaseMidi.h"

class MidiSender : protected BaseMidi {
public:
    libremidi::midi_out midi_out;

    // Singleton instance function
    static MidiSender* Instance();
private:
    MidiSender();

    static MidiSender* _instance;
};

#endif