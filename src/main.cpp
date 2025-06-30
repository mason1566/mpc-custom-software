#include <iostream>
#include <vector>
#include <libremidi/libremidi.hpp>
#include <string>
#include <sstream>
#include <iomanip>

std::string bytesToHex(const std::vector<unsigned char>& bytes) {
    std::stringstream ss;
    ss << std::hex << std::setfill('0'); // Set output to hexadecimal and pad with '0'
    for (unsigned char byte : bytes) {
	ss << std::setw(2) << static_cast<int>(byte); // Each byte is 2 hex digits
    }
    return ss.str();
}

int main() {
    
    libremidi::observer obs;

    // Get input and output ports and store them in vectors
    std::vector<libremidi::input_port> inputPorts = obs.get_input_ports();
    std::vector<libremidi::output_port> outputPorts = obs.get_output_ports();

    std::cout << "INPUT: " << inputPorts[0].port_name << "\nOUTPUT: " << outputPorts[0].port_name << std::endl; 
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    // create a callback function for device output
    auto my_callback = [](const libremidi::message& message) {
	    std::string code = bytesToHex(message.bytes); 
	    std::cout << code << std::endl;
    };

    // create the midi object
    libremidi::midi_in midi_in { 
	libremidi::input_configuration{ .on_message = my_callback }
    };

    midi_in.open_port(inputPorts[0]);

    // wait for midi input
    while (true) {}
}
