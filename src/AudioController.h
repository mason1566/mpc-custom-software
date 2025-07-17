#pragma once
#include "miniaudio.h"

class AudioController {
public:
    AudioController();
    ~AudioController();
    void MakeSound();

protected:
    ma_result result;
    ma_engine engine;
};