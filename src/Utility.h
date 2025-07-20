#ifndef UTILITY
#define UTILITY
#include <vector>

namespace MPC_CONSTANTS {

    // static std::vector<int> DRUMPAD_IDENTIFIERS { 0x25, 0x24, 0x2A, 0x52, 0x28, 0x26, 0x2E, 0x2C, 0x30, 0x2F, 0x2D, 0x2B, 0x31, 0x37, 0x33, 0x35 };

    static int DRUMPAD_COUNT = 16;
    static int DRUMPAD_MIDI_VALUES[] { 37, 36, 42, 82, 40, 38, 46, 44, 48, 47, 45, 43, 49, 55, 51, 53 };

    namespace MIDI_MESSAGES {
        static int DRUMPAD_DOWN = 0x99;
        static int DRUMPAD_UP = 0x89;
    }
}
#endif