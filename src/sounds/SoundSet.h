#ifndef SOUND_SET
#define SOUND_SET

#include "SoundFile.h"

#include <vector>

class SoundSet {
public:
    SoundSet(std::string name) : name(name) {} // Constructor

    std::string getName() { return name; }
    void setName(std::string name) { name = name; }
    SoundFile getSoundFile(int index) const;
    void addSoundFile(SoundFile sound) { soundFiles.push_back(sound); }
    size_t size() { return soundFiles.size(); }
    // void removeSound(Sound* sound);
protected:
    std::vector<SoundFile> soundFiles;
    std::string name;
};

#endif