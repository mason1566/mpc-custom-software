#include "SoundSet.h"

SoundFile SoundSet::getSoundFile(int index) const {
    if (index < soundFiles.size() && index >= 0) {
        return soundFiles[index];
    }
    throw index;
}