#ifndef BASE_STATE
#define BASE_STATE

#include "Utility.h"
#include <string>

class BaseState {
public:
    std::string name;

    BaseState(std::string stateName) : name(stateName) {}
    virtual void performOperation();
};

#endif