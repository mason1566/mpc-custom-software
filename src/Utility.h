#ifndef UTILITY
#define UTILITY
#include <vector>
#include <string>

namespace MPC_CONSTANTS {

    // static std::vector<int> DRUMPAD_IDENTIFIERS { 0x25, 0x24, 0x2A, 0x52, 0x28, 0x26, 0x2E, 0x2C, 0x30, 0x2F, 0x2D, 0x2B, 0x31, 0x37, 0x33, 0x35 };

    static int DRUMPAD_COUNT = 16;
    static int DRUMPAD_MIDI_VALUES[] { 37, 36, 42, 82, 40, 38, 46, 44, 48, 47, 45, 43, 49, 55, 51, 53 };

    namespace MIDI_MESSAGES {
        // OUTPUT
        static unsigned char MIDI_CONTROL_CHANGE = 0xB0;

        // INPUT
        static int DRUMPAD_DOWN = 0x99;
        static int DRUMPAD_UP = 0x89;
    }

    namespace INPUT_TYPES {
        static std::string BUTTON_INPUT { "BUTTON_INPUT" };
        static std::string DRUMPAD_INPUT { "DRUMPAD_INPUT" };
    }
}

namespace MPC_STATES {
    static std::string COPY_PASTE_SOUND { "COPY_PASTE_SOUND" };
    static std::string CHANGE_SOUND { "CHANGE_SOUND" };
    static std::string CHANGE_VOLUME { "CHANGE_VOLUME" };
    static std::string CHANGE_SOUND_START_TIME { "CHANGE_SOUND_START_TIME" };
    static std::string CHANGE_SOUND_END_TIME { "CHANGE_SOUND_END_TIME" };
}

#endif