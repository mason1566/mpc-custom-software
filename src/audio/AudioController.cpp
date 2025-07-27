#include "AudioController.h"

#include <iostream>

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

void AudioController::PlaySound(Sound& sound) {
    // std::cout << sound.name << std::endl;
    ma_engine_play_sound(&engine, sound.path.string().c_str(), NULL);
}