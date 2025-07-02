#include <iostream>
#include <vector>
#include <libremidi/libremidi.hpp>
#include <string>
#include <sstream>
#include <iomanip>
#include <random>
#include <functional>

class Pad 
{
public:
    unsigned char id; // the pad number
    unsigned char code; // the code sent from the device corresponding to this pad
    unsigned int padMultiplier = 0; // 0 = off, 1 = on.

    Pad(unsigned char id) : id {id} {}
    void togglePad() {
        padMultiplier = (padMultiplier > 0) ? 0 : 1;
    }
};

std::string bytesToHex(const std::vector<unsigned char>& bytes) 
{
    std::stringstream ss;
    ss << std::hex << std::setfill('0'); // Set output to hexadecimal and pad with '0'
    for (unsigned char byte : bytes) {
	ss << std::setw(2) << static_cast<int>(byte); // Each byte is 2 hex digits
    }
    return ss.str();
}

// colour values ranging from 0-127 (00-7F)
void setPadLed(libremidi::midi_out &midi_out, Pad pad, unsigned char red, unsigned char green, unsigned char blue) 
{
    // normalize values
    red = (red > 0x7F) ? 0x7F : red;
    green = (green > 0x7F) ? 0x7F : green;
    blue = (blue > 0x7F) ? 0x7F : blue;

    red = (red < 0) ? 0x00 : red;
    green = (green < 0) ? 0x00 : green;
    blue = (blue < 0) ? 0x00 : blue;

    unsigned char bytes[12] = { 0xF0, 0x47, 0x47, 0x4A, 0x65, 0x00, 0x04, pad.id, red, green, blue, 0xF7 };

    midi_out.send_message(bytes, sizeof(bytes));
}

int main() 
{
    // setup random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> randLedColour(0, 127); // DrumPad LEDs expect numbers from 0-127

    // setup vector of 16 pads
    const int padCount = 16;

    std::vector<Pad> pads{};
    for (int i = 0; i < padCount; i++) {
        Pad pad { static_cast<unsigned char>(i) };
        pads.push_back(pad);
    }

    // set pad codes
    // pads[0].code = 0x25;
    // pads[1].code = 0x24;
    // pads[2].code = 0x2a;
    // pads[3].code = 0x52;
    // pads[4].code = 0x28;
    // pads[5].code = 0x26;
    // pads[6].code = 0x2e;
    // pads[7].code = 0x2c;
    // pads[8].code = 0x30;
    // pads[9].code = 0x2f;
    // pads[10].code = 0x2d;
    // pads[11].code = 0x2b;
    // pads[12].code = 0x31;
    // pads[13].code = 0x37;
    // pads[14].code = 0x33;
    // pads[15].code = 0x35;

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

    for (Pad pad : pads) {
        setPadLed(midi_out, pad, (unsigned char) randLedColour(gen), (unsigned char) randLedColour(gen), (unsigned char) randLedColour(gen));
    }

    // wait for midi input
    while (true) {}
}
