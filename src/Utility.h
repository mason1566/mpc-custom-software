#ifndef MIDI_UTILITY
#define MIDI_UTILITY
#include <vector>
#include <string>

namespace MPC_CONSTANTS {

    // static std::vector<int> DRUMPAD_IDENTIFIERS { 0x25, 0x24, 0x2A, 0x52, 0x28, 0x26, 0x2E, 0x2C, 0x30, 0x2F, 0x2D, 0x2B, 0x31, 0x37, 0x33, 0x35 };

    static int DRUMPAD_COUNT = 16;
    static int DRUMPAD_MIDI_VALUES[] { 37, 36, 42, 82, 40, 38, 46, 44, 48, 47, 45, 43, 49, 55, 51, 53 };

    namespace BUTTON_MIDI_VALUES {
        static int TOUCH_STRIP_BUTTON = 0;
        static int PAD_MUTE = 4;
        static int ERASE = 9;
        static int NOTE_REPEAT = 11;
        static int QUANTIZE = 12;
        static int TRACK_SELECT = 13;
        static int PROGRAM_SELECT = 14;
        static int TC_ON_OFF = 15;
        static int SAMPLE_START = 33;
        static int SAMPLE_END = 34;
        static int PAD_BANK_AE = 35;
        static int PAD_BANK_BF = 36;
        static int PAD_BANK_CG = 37;
        static int PAD_BANK_DH = 38;
        static int FULL_LEVEL = 39;
        static int SIXTEEN_LEVEL = 40;
        static int SAMPLE_SELECT = 42;
        static int SHIFT = 49;
        static int BROWSE = 50;
        static int MAIN = 52;
        static int TAP_TEMPO = 53;
        static int PLUS = 54;
        static int MINUS = 55;
        static int ZOOM = 66;
        static int UNDO = 67;
        static int LEFT = 68;
        static int RIGHT = 69;
        static int LOCATE = 70;
        static int LEFT_LEFT = 71;
        static int RIGHT_RIGHT = 72;
        static int RECORD = 73;
        static int AUTOMATION_READ_WRITE = 75;
        static int TUNE = 79;
        static int OVERDUB = 80;
        static int STOP = 81;
        static int PLAY = 82;
        static int PLAY_START = 83;
        static int JOG_WHEEL = 111;
        static int MODE = 114;
        static int COPY = 122;
    }

    namespace MIDI_MESSAGES {
        // OUTPUT
        static unsigned char MIDI_CONTROL_CHANGE = 0xB0;

        /* INPUT */
        // Drumpads
        static const int DRUMPAD_DOWN = 0x99;
        static const int DRUMPAD_UP = 0x89;
        static const int DRUMPAD_HOLD = 0xA9;

        // Buttons
        static const int BUTTON_DOWN = 0x90;
        static const int BUTTON_UP = 0x80;

        // Knob
        static const int KNOB_TURN = 0xB0;
        static const int KNOB_TURN_CLOCKWISE_VELOCITY = 0x01;
        static const int KNOB_TURN_COUNTER_CLOCKWISE_VELOCITY = 0x7F;
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