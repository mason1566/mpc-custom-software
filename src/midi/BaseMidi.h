#ifndef BASE_MIDI
#define BASE_MIDI

#include <libremidi/libremidi.hpp>
#include <memory>

class BaseMidi {
protected:
    static libremidi::observer* getMidiObserver();
private:
    static libremidi::observer* _observer;
};

#endif