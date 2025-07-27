#ifndef MPC_SOUND
#define MPC_SOUND

#include <filesystem>
#include <string>

class Sound {
public:
    std::filesystem::path path;
    std::string name;
    float duration;
    float startTime;
    float endTime;

    Sound(std::filesystem::path path, std::string name, float duration, float startTime, float endTime) : path(path), name(name), duration(duration), startTime(startTime), endTime(endTime) {}
};

#endif