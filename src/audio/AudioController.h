#ifndef AUDIO_CONTROLLER
#define AUDIO_CONTROLLER

#include "miniaudio.h"
#include "../input/DrumPad.h"
#include "../sounds/SoundFile.h"

class AudioController {
public:
    void MakeSound();
    void MakeSound(DrumPad& drumpad);
    void PlaySound(SoundFile& sound);

    static AudioController& instance();
protected:
    ma_result result;
    ma_engine engine;

    AudioController();
    ~AudioController();
};
#endif