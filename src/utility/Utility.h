#ifndef MIDI_UTILITY
#define MIDI_UTILITY
#include <vector>
#include <string>

namespace MPC_CONSTANTS {

    // static std::vector<int> DRUMPAD_IDENTIFIERS { 0x25, 0x24, 0x2A, 0x52, 0x28, 0x26, 0x2E, 0x2C, 0x30, 0x2F, 0x2D, 0x2B, 0x31, 0x37, 0x33, 0x35 };

    static int DRUMPAD_COUNT = 16;
    static int DRUMPAD_MIDI_VALUES[] { 37, 36, 42, 82, 40, 38, 46, 44, 48, 47, 45, 43, 49, 55, 51, 53 };

    namespace BUTTON_MIDI_VALUES {
        static const int TOUCH_STRIP_BUTTON = 0;
        static const int PAD_MUTE = 4;
        static const int ERASE = 9;
        static const int NOTE_REPEAT = 11;
        static const int QUANTIZE = 12;
        static const int TRACK_SELECT = 13;
        static const int PROGRAM_SELECT = 14;
        static const int TC_ON_OFF = 15;
        static const int SAMPLE_START = 33;
        static const int SAMPLE_END = 34;
        static const int PAD_BANK_AE = 35;
        static const int PAD_BANK_BF = 36;
        static const int PAD_BANK_CG = 37;
        static const int PAD_BANK_DH = 38;
        static const int FULL_LEVEL = 39;
        static const int SIXTEEN_LEVEL = 40;
        static const int SAMPLE_SELECT = 42;
        static const int SHIFT = 49;
        static const int BROWSE = 50;
        static const int MAIN = 52;
        static const int TAP_TEMPO = 53;
        static const int PLUS = 54;
        static const int MINUS = 55;
        static const int ZOOM = 66;
        static const int UNDO = 67;
        static const int LEFT = 68;
        static const int RIGHT = 69;
        static const int LOCATE = 70;
        static const int LEFT_LEFT = 71;
        static const int RIGHT_RIGHT = 72;
        static const int RECORD = 73;
        static const int AUTOMATION_READ_WRITE = 75;
        static const int TUNE = 79;
        static const int OVERDUB = 80;
        static const int STOP = 81;
        static const int PLAY = 82;
        static const int PLAY_START = 83;
        static const int JOG_WHEEL = 111;
        static const int MODE = 114;
        static const int COPY = 122;
        static const int KNOB = 100;
        static const int KNOB_BUTTON = 111;
    }
}

namespace MIDI_INPUT_SIGNALS {
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

enum class InputType {
    DRUMPAD_INPUT, BUTTON_INPUT
};

enum class InputSignal {
    DRUMPAD_DOWN, DRUMPAD_HOLD, DRUMPAD_UP,
    BUTTON_DOWN, BUTTON_UP, 
    KNOB_TURN_CLOCKWISE, KNOB_TURN_COUNTER_CLOCKWISE,
    ERROR
};

// namespace MPC_STATES {
//     static std::string COPY_PASTE_SOUND { "COPY_PASTE_SOUND" };
//     static std::string CHANGE_SOUND { "CHANGE_SOUND" };
//     static std::string CHANGE_VOLUME { "CHANGE_VOLUME" };
//     static std::string CHANGE_SOUND_START_TIME { "CHANGE_SOUND_START_TIME" };
//     static std::string CHANGE_SOUND_END_TIME { "CHANGE_SOUND_END_TIME" };
// }

#endif