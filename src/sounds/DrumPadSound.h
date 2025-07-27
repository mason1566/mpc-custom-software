#ifndef DRUMPAD_SOUND
#define DRUMPAD_SOUND

#include "SoundFile.h"
#include "SoundSet.h"

#include <vector>

class DrumPadSound {
public:
    DrumPadSound(std::vector<SoundSet>& soundSets) : soundSets(soundSets), soundSetIndex(0), soundIndex(0) {}
    DrumPadSound(std::vector<SoundSet>& soundSets, int soundSetIndex, int soundIndex);

    SoundFile& getSound();
    void goNextSound();
    void goPreviousSound();
    void goNextSoundSet();
    void goPreviousSoundSet();
private:
    std::vector<SoundSet>& soundSets;
    int soundSetIndex;
    int soundIndex;
};

#endif