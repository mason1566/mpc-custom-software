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

void AudioController::MakeSound(SoundFile* sound) {
    if (sound) {
        // std::cout << "Signal DRUMPAD_DOWN from Pad: " << drumpad.padNumber << std::endl;
        // std::cout << sound << std::endl;
        PlaySound(sound->getPath().string().c_str());
    }
    else {
        MakeSound();
    }
}

void AudioController::MakeSound() {
    std::cout << "Making Sound!\n";
    ma_engine_play_sound(&engine, "../src/sounds/Blood Snare.wav", NULL);
};

void AudioController::PlaySound(std::string soundPath) {
    // std::cout << sound->name << std::endl;
    // std::cout << "Playing Sound!\n";
    ma_engine_play_sound(&engine, soundPath.c_str(), NULL);
}

