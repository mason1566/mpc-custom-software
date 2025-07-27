#ifndef SOUND_LIBRARY
#define SOUND_LIBRARY

#include "Sound.h"
#include "SoundSet.h"

#include <filesystem>
#include <vector>
#include <unordered_map>

class SoundLibrary {
public:
    std::vector<Sound*> sounds;
    std::vector<SoundSet> soundCategories;
    std::unordered_map<std::string, SoundSet*> soundCategoryMap;
    
    // void addCategory(SoundSet sounds) { soundCategories.push_back(sounds); }
    // void removeCategory(SoundSet sounds);
    SoundLibrary();
protected:
    std::vector<Sound> getSoundsInDirectory(std::filesystem::path path);
};

#endif