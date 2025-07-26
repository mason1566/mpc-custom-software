#include "BaseMidi.h"

libremidi::observer& BaseMidi::getMidiObserver() {
    static libremidi::observer observer;
    return observer;
};

