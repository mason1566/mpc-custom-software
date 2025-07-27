#include "DrumPadSound.h"

// #include <iostream>

DrumPadSound::DrumPadSound(std::vector<SoundSet>& soundSets, int soundSetIndex, int soundIndex)
    : soundSets(soundSets), soundSetIndex(soundSetIndex), soundIndex(soundIndex)
{
    // Handle invalid indexes
    if (soundSetIndex >= soundSets.size() || soundSetIndex < 0) {
        std::string msg { "DrumPadSound::DrumPadSound(): Invalid Parameter: soundSetIndex" };
        throw std::invalid_argument(msg);
    }
    else if (soundIndex < 0 || soundIndex >= soundSets[soundSetIndex].size()) {
        std::string msg { "DrumPadSound::DrumPadSound(): Invalid Parameter: soundIndex" };
        throw std::invalid_argument(msg);
    }
};

SoundFile& DrumPadSound::getSound() {
    return soundSets[soundSetIndex].getSoundFile(soundIndex);
};

void DrumPadSound::goNextSound() {
    soundIndex++;

    if (soundIndex >= soundSets[soundSetIndex].size()) {
        soundIndex = 0;
    }

    // std::cout << "Sound Index: " << soundIndex << ", SoundSet Index: " << soundSetIndex << std::endl;
};

void DrumPadSound::goPreviousSound() {
    soundIndex--;

    if (soundIndex < 0) {
        soundIndex = soundSets[soundSetIndex].size() - 1;
    }
    // std::cout << "Sound Index: " << soundIndex << ", SoundSet Index: " << soundSetIndex << std::endl;
};

void DrumPadSound::goNextSoundSet() {
    soundIndex = 0;
    soundSetIndex++;

    if (soundSetIndex >= soundSets.size()) {
        soundSetIndex = 0;
    }
    soundIndex = 0;
    // std::cout << "Sound Index: " << soundIndex << ", SoundSet Index: " << soundSetIndex << std::endl;
};

void DrumPadSound::goPreviousSoundSet() {
    soundIndex = 0;
    soundSetIndex--;

    if (soundSetIndex < 0) {
        soundSetIndex = soundSets.size() - 1;
    }
    // std::cout << "Sound Index: " << soundIndex << ", SoundSet Index: " << soundSetIndex << std::endl;
};