#ifndef SOUND_FILE
#define SOUND_FILE

#include <filesystem>

class SoundFile {
public:
    SoundFile(std::filesystem::path soundPath) : soundPath(soundPath) {}

    std::filesystem::path getPath() { return soundPath; }
    std::string getFileName() { return soundPath.filename().string(); }
protected:
    std::filesystem::path soundPath;
};

#endif