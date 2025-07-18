#ifndef UTILITY
#define UTILITY
#include <vector>

namespace MPC_CONSTANTS {

    static std::vector<int> DRUMPAD_IDENTIFIERS { 0x25, 0x24, 0x2A, 0x52, 0x28, 0x26, 0x2E, 0x2C, 0x30, 0x2F, 0x2D, 0x2B, 0x31, 0x37, 0x33, 0x35 };

    static std::vector<int> FULL_DRUMPAD_IDENTIFIERS { 
        0x002500, 0x002400, 0x002A00, 0x005200, 0x002800, 0x002600, 0x002E00, 0x002C00,
        0x003000, 0x002F00, 0x002D00, 0x002B00, 0x003100, 0x003700, 0x003300, 0x003500 
    };

    namespace MIDI_MESSAGES {
        static int DRUMPAD_DOWN = 0x99;
        static int DRUMPAD_UP = 0x89;
    }
}
#endif