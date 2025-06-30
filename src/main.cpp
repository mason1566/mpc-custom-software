#include <iostream>
#include <vector>
#include <libremidi/libremidi.hpp>

int main() {
    
    libremidi::observer obs;
    for(const libremidi::input_port& port : obs.get_input_ports()) 
    {
	std::cout << port.port_name << "\n";
    }

    for(const libremidi::output_port& port : obs.get_output_ports()) 
    {
	std::cout << port.port_name << "\n";
    }

    // Get input and output ports and store them in vectors
    std::vector<libremidi::input_port> inputPorts = obs.get_input_ports();
    std::vector<libremidi::output_port> outputPorts = obs.get_output_ports();
}
