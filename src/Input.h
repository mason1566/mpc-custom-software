#ifndef INPUT
#define INPUT

#include "RGB.h"
#include "Utility.h"
#include <string>

class Input {
public:
    int midiCode;
    std::string inputType;
    
    Input(int midiCode, std::string inputType) : midiCode(midiCode), inputType(inputType) {}
};

#endif