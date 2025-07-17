#include "AudioController.h"

AudioController::AudioController() {
    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        return;
    }
}

AudioController::~AudioController() {
    ma_engine_uninit(&engine);
}

void AudioController::MakeSound() {
    ma_engine_play_sound(&engine, "../src/sounds/Blood Snare.wav", NULL);
};