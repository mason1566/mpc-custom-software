#include "SoundLibrary.h"

#include <iostream>

SoundLibrary::SoundLibrary() {
    // for (const auto& entry : std::filesystem::directory_iterator(""))
    // std::cout << std::filesystem::current_path().string() << std::endl;
    // Current path is /Users/masonjohnson/Projects/Cpp/MPC/build

    std::vector<std::filesystem::path> soundDirectories;

    std::filesystem::path soundDirPath = "/Users/masonjohnson/Projects/Cpp/MPC/sounds";
   
    // Collect all the subdirectories of the sounds folder (non-recursive)
    for (const auto& entry : std::filesystem::directory_iterator(soundDirPath)) {
        if (entry.is_directory()) {
            soundDirectories.push_back(entry.path());
        }
    }

    for (const auto& dir : soundDirectories) {
        SoundSet(dir.lexically_normal().filename().string()); // lexically_normal removes the trailing slash (if present). This is because trailing slashes cause an emptry string to be returned instead

        for (const auto& file : std::filesystem::directory_iterator(dir)) {
            if (file.is_regular_file()) {
                auto ext = file.path().extension().string();
                if (ext == ".wav" || ext == ".mp3" || ext == ".flac") {
                    std::cout << file.path() << std::endl;
                }
            }
        }
    }
};