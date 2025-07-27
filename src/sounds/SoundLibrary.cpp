#include "SoundLibrary.h"

#include "SoundFile.h"

#include <iostream>

SoundLibrary::SoundLibrary(std::function<void()> setupDoneCallback) {
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

    // Create a soundset for each sound directory and add sounds from that directory
    for (const auto& dir : soundDirectories) {
        soundSets.push_back({ dir.lexically_normal().filename().string() }); // lexically_normal removes the trailing slash (if present). This is because trailing slashes cause an emptry string to be returned instead

        for (const auto& file : std::filesystem::directory_iterator(dir)) {
            if (file.is_regular_file()) {
                auto ext = file.path().extension().string();
                if (ext == ".wav" || ext == ".mp3" || ext == ".flac") {
                    soundSets.back().addSoundFile({ file.path() });
                }
            }
        }
        
        // Set "default_library" to be the first in the soundSets vector
        if (soundSets.back().getName() == "default_library") {
            std::swap(soundSets[0], soundSets.back()); // Use swap to safely swap in a vector
        }
    }
    setupDoneCallback();
};

SoundSet& SoundLibrary::getSoundSet(int index) {
    if (index < soundSets.size() && index >= 0) {
        return soundSets[index];
    }
    throw index;
}
