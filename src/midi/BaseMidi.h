#ifndef BASE_MIDI
#define BASE_MIDI

#include <libremidi/libremidi.hpp>
#include <memory>

class BaseMidi {
public:
    static libremidi::observer& getMidiObserver();
};

#endif