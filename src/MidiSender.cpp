#include "MidiSender.h"

MidiSender* MidiSender::_instance = nullptr;

MidiSender* MidiSender::Instance() {
    if (!_instance)
        _instance = new MidiSender;
    return _instance;
}

MidiSender::MidiSender() {
    midi_out.open_port(getMidiObserver()->get_output_ports()[0]);
}