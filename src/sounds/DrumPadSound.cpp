#include "DrumPadSound.h"

DrumPadSound::DrumPadSound(std::vector<SoundSet>& soundSets, int soundSetIndex, int soundIndex)
    : soundSets(soundSets), soundSetIndex(soundSetIndex), soundIndex(soundIndex)
{
    // Handle invalid indexes
    if (soundSetIndex >= soundSets.size() || soundSetIndex < 0) {
        std::string msg { "DrumPadSound::DrumPadSound(): Invalid Parameter: soundSetIndex = " + soundSetIndex };
        throw std::invalid_argument(msg);
    }
    else if (soundIndex < 0 || soundIndex >= soundSets[soundSetIndex].size()) {
        std::string msg { "DrumPadSound::DrumPadSound(): Invalid Parameter: soundIndex = " + soundSetIndex };
        throw std::invalid_argument(msg);
    }
};

SoundFile& DrumPadSound::getSound() {
    return soundSets[soundSetIndex].getSoundFile(soundIndex);
};