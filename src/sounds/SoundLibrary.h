#ifndef SOUND_LIBRARY
#define SOUND_LIBRARY

#include "SoundSet.h"

#include <filesystem>
#include <vector>
#include <unordered_map>
#include <functional>

class SoundLibrary {
public:    
    SoundLibrary(std::function<void(std::vector<SoundSet>&)> setupDoneCallback);

    SoundSet& getSoundSet(int index);
protected:
    std::vector<SoundSet> soundSets;
};

#endif