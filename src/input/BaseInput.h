#ifndef BASE_INPUT
#define BASE_INPUT

#include "../utility/Utility.h"
#include <string>

class BaseInput {
public:
    int midiValue;
    int velocity = 0;

    
    BaseInput(int midiValue) : midiValue(midiValue) {}
    virtual ~BaseInput() = default;
};

#endif