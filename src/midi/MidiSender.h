#ifndef MIDI_SENDER
#define MIDI_SENDER

#include "BaseMidi.h"
#include "../utility/RGB.h"

class MidiSender : protected BaseMidi {
public:
    void setPadRGB(int padNumber, RGB colour);

    // Singleton instance function
    static MidiSender& instance();
private:
    libremidi::midi_out midi_out;

    MidiSender();
};

#endif