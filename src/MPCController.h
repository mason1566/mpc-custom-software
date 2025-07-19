#ifndef MPC_CONTROLLER
#define MPC_CONTROLLER

#include "MidiController.h"
#include "AudioController.h"
#include "Input.h"
#include "Utility.h"
#include "RGB.h"

#include <vector>
#include <iomanip>
#include <iostream>
#include <unordered_map>

// Singleton
class MPCController {
public:
    MidiController* midi;
    std::vector<Button> buttons;
    std::vector<DrumPad> drumpads;
    AudioController audio;
    std::unordered_map<int, Input*> input_map;

    void Boot();
    void SetPadRGB(DrumPad* pad, RGB colour) { pad->setLightColour(colour); };

    // Singleton Instance function. This is the accessor to the shared MPCController instance
    static MPCController* Instance();
protected:
    // Protected constructor for singleton pattern
    MPCController();

    // Common MPCController Instance variable
    static MPCController* _instance;
};

#endif