#include <iostream>
#include <vector>
#include <libremidi/libremidi.hpp>
#include <string>
#include <sstream>
#include <iomanip>
#include <random>
#include <functional>

class DrumPad 
{
public:
    unsigned char id; // the drumpad id number
    unsigned char code; // the code sent from mpc device corresponding to this drumpad
    unsigned int padMultiplier = 0; // 0 = off, 1 = on.
    libremidi::midi_out &midi_out;

    DrumPad(unsigned char id, libremidi::midi_out &midi_out) : id {id}, midi_out {midi_out} {}
    DrumPad(int id, libremidi::midi_out &midi_out) : id {(unsigned char) id}, midi_out {midi_out} {}

    void setPadLed(float redPercent, float greenPercent, float bluePercent) {
        // normalize values
        redPercent =    (redPercent > 1) ? 1 : redPercent;
        greenPercent =  (greenPercent > 1) ? 1 : greenPercent;
        bluePercent =   (bluePercent > 1) ? 1 : bluePercent;

        redPercent =    (redPercent < 0) ? 0 : redPercent;
        greenPercent =  (greenPercent < 0) ? 0 : greenPercent;
        bluePercent =   (bluePercent < 0) ? 0 : bluePercent;

        unsigned char red = 0x7F, green = 0x7F, blue = 0x7F;

        red *= redPercent;
        green *= greenPercent;
        blue *= bluePercent;

        unsigned char bytes[12] = { 0xF0, 0x47, 0x47, 0x4A, 0x65, 0x00, 0x04, id, red, green, blue, 0xF7 };

        midi_out.send_message(bytes, sizeof(bytes));
    }
};

std::string bytesToHex(const std::vector<unsigned char> &bytes) 
{
    std::stringstream ss;
    ss << std::hex << std::setfill('0'); // pad hex with 0s

    for (unsigned char byte : bytes) {
        ss << std::setw(2) << static_cast<int>(byte);
    }
    return ss.str();
}

int main() 
{
    libremidi::observer obs;

    // Get input and output ports and store them in vectors
    std::vector<libremidi::input_port> inputPorts = obs.get_input_ports();
    std::vector<libremidi::output_port> outputPorts = obs.get_output_ports();

    std::cout << "INPUT: " << inputPorts[0].port_name << "\nOUTPUT: " << outputPorts[0].port_name << std::endl; 
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    // create a callback function for device output
    auto my_callback = [](const libremidi::message& message) {
	    std::string code = bytesToHex(message.bytes); 
        if (code[0] == '9' || code[0] == '8')
	        std::cout << code << std::endl;
    };

    // create the midi in object
    libremidi::midi_in midi_in { 
	libremidi::input_configuration{ .on_message = my_callback }
    };

    midi_in.open_port(inputPorts[0]); // set midi in port to MPC Public Port
	
    // create the midi out object
    libremidi::midi_out midi_out;

    midi_out.open_port(outputPorts[0]);


    // set up vector of 16 drumpads
    const int drumpadCount = 16;

    std::vector<DrumPad> pads{};

    for (int i = 0; i < drumpadCount; i++) {
        DrumPad pad { i, midi_out };
        pads.push_back(pad);
    }

    for (DrumPad pad : pads) {
        pad.setPadLed(0, 1, 1);
    }

    // wait for midi input
    while (true) {}
}