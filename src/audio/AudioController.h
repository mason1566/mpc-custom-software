#ifndef AUDIO_CONTROLLER
#define AUDIO_CONTROLLER

#include "miniaudio.h"

class AudioController {
public:
    void MakeSound();
    // void PlaySound(Sound* sound);

    static AudioController& instance();
protected:
    ma_result result;
    ma_engine engine;

    AudioController();
    ~AudioController();
};
#endif