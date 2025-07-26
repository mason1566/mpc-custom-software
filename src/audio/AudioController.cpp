#include "AudioController.h"

// Singleton Pattern
AudioController& AudioController::instance() {
    static AudioController instance;
    return instance;
}

// Constructor
AudioController::AudioController() {
    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        return;
    }
}

// Destructor
AudioController::~AudioController() {
    ma_engine_uninit(&engine);
}

void AudioController::MakeSound() {
    ma_engine_play_sound(&engine, "../src/sounds/Blood Snare.wav", NULL);
};