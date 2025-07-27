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

void AudioController::MakeSound(DrumPad& drumpad) {
    if (drumpad.sound) {
        PlaySound(drumpad.sound->getSound());
    }
    else {
        MakeSound();
    }
}

void AudioController::MakeSound() {
    std::cout << "Making Sound!\n";
    ma_engine_play_sound(&engine, "../src/sounds/Blood Snare.wav", NULL);
};

void AudioController::PlaySound(SoundFile& sound) {
    // std::cout << sound->name << std::endl;
    // std::cout << "Playing Sound!\n";
    ma_engine_play_sound(&engine, sound.getPath().string().c_str(), NULL);
}

