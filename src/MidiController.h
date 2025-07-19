#ifndef MIDI_CONTROLLER
#define MIDI_CONTROLLER

#include <libremidi/libremidi.hpp>
#include "RGB.h"

// Singleton
class MidiController {
public:
    static MidiController* Instance();

    void sendMessage(unsigned char bytes[], size_t size) { midi_out.send_message(bytes, size); };
    void SetPadRGB(int padNumber, RGB colour);
protected:
    static MidiController* _instance;
    
    libremidi::observer observer;
    std::unique_ptr<libremidi::midi_in> midi_in;
    libremidi::midi_out midi_out;

    MidiController();
    void HandleMidiMessage(libremidi::message message);
};

#endif