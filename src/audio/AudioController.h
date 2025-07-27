#ifndef AUDIO_CONTROLLER
#define AUDIO_CONTROLLER

#include "miniaudio.h"
#include "../sounds/SoundFile.h"

#include <string>

class AudioController {
public:
    void MakeSound();
    void MakeSound(SoundFile* sound);
    void PlaySound(std::string soundPath);

    static AudioController& instance();
protected:
    ma_result result;
    ma_engine engine;

    AudioController();
    ~AudioController();
};
#endif