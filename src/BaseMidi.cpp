#include "BaseMidi.h"

libremidi::observer* BaseMidi::_observer = nullptr;

libremidi::observer* BaseMidi::getMidiObserver() {
    if (!_observer) 
        _observer = new libremidi::observer;
    return _observer;
};

