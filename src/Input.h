#ifndef INPUT
#define INPUT

#include "RGB.h"

// Forward declaration for MPCController
class MPCController {
public:
    static MPCController* Instance();
    void SetPadRGB(DrumPad* pad, RGB colour);
};

class Input {
public:
    int idCode;
    
    Input(int id) : idCode {id} {};
};

class Button : Input {
public:
    Button(int id) : Input(id) {};
};

class DrumPad : Input {
public:
    int padNumber; // MPC signals involving drumpad use idCode for incoming and padNumber for outgoing
    bool isLightOn;

    DrumPad(int id, int padNum);
    void setLightColour(RGB colour);
protected:
    RGB _lightColour { RGB::WHITE };
};

#endif