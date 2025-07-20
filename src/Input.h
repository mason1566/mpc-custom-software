#ifndef INPUT
#define INPUT

#include "RGB.h"
#include "Utility.h"
#include <string>

class Input {
public:
    int midiCode;
    std::string inputType;
    std::string name;
    
    Input(int midiCode, std::string inputType, std::string name) : midiCode(midiCode), inputType(inputType), name(name) {}
};

#endif