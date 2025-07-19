#include "MidiController.h"
// #include <iostream>
// #include <iomanip>

/* SINGLETON INSTANCE IMPLEMENTATION */
MidiController* MidiController::_instance = nullptr;

MidiController* MidiController::Instance() {
    if (!_instance)
        _instance = new MidiController;
    return _instance;
};

/* CONSTRUCTOR */
MidiController::MidiController() {
    auto callback = [this](libremidi::message&& message) {
        this->HandleMidiMessage(message);
    };

    midi_in = std::make_unique<libremidi::midi_in>(
        libremidi::input_configuration{ .on_message = callback }
    );

    // Open midi ports
    midi_in->open_port(observer.get_input_ports()[0]);
    midi_out.open_port(observer.get_output_ports()[0]);
}

void MidiController::HandleMidiMessage(libremidi::message message) {
    if (midiCallbackFunction)
        midiCallbackFunction(message);
}

void MidiController::SetPadRGB(int padNumber, RGB colour) {
    // Midi sysex message format for controlling drumpad LED values is as follows:
    // { 
    //      msg_start, mfg_id, dev_id, model_id, msg_type, data_length, data_length_2, 
    //      PAD_NUM, RED_VALUE (0-127), GREEN_VALUE (0-127), BLUE_VALUE (0-127), msg_end 
    // }
    // We are only interested in modifying the PAD_NUM, RED_VALUE, GREEN_VALUE, and BLUE_VALUE.
    
    // Convert colour values into unsigned char. This is because midi_out.send_message expects unsigned char values
    unsigned char padNum = static_cast<unsigned char>(padNumber);
    unsigned char red = static_cast<unsigned char>(colour.getRed());
    unsigned char green = static_cast<unsigned char>(colour.getGreen());
    unsigned char blue = static_cast<unsigned char>(colour.getBlue());

    unsigned char bytes[12] = { 
        0xF0, 0x47, 0x47, 0x4A, 0x65, 0x00, 0x04, 
        padNum, red, green, blue, 0xF7 
    };

    midi_out.send_message(bytes, sizeof(bytes));
}