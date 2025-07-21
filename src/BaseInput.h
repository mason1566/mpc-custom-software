#ifndef BASE_INPUT
#define BASE_INPUT

#include "Utility.h"
#include <string>

class BaseInput {
public:
    int midiCode;
    std::string inputType;
    
    BaseInput(int midiCode, std::string inputType) : midiCode(midiCode), inputType(inputType) {}
    virtual ~BaseInput() = default;
};

#endif