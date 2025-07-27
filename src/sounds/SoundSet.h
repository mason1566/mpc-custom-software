#ifndef SOUND_SET
#define SOUND_SET

#include "Sound.h"

#include <vector>

class SoundSet {
public:
    std::string name;
    std::vector<Sound*> sounds;
    bool isLocked = false;

    SoundSet(std::string name) : name(name) {} // Constructor

    void addSound(Sound* sound) { sounds.push_back(sound); }
    // void removeSound(Sound* sound);
};

#endif