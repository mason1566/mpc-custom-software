#ifndef AUDIO_CONTROLLER
#define AUDIO_CONTROLLER

#include "miniaudio.h"

class AudioController {
public:
    void MakeSound();

    static AudioController* Instance();
protected:
    ma_result result;
    ma_engine engine;

    static AudioController* _instance;

    AudioController();
    ~AudioController();
};
#endif