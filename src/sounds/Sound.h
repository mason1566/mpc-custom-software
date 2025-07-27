#ifndef MPC_SOUND
#define MPC_SOUND

#include <filesystem>
#include <string>

class Sound {
public:
    std::filesystem::path path;
    std::string name;
    float duration = 0.0f;
    float startTime = 0.0f;
    float endTime = 0.0f;
    float volume = 1.0f;

    Sound(std::filesystem::path path, std::string name) : path(path), name(name) {}
};

#endif