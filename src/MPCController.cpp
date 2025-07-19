#include "MPCController.h"

/* SINGLETON INSTANCE IMPLEMENTATION */
MPCController* MPCController::_instance = nullptr;

MPCController* MPCController::Instance() {
    if (!_instance) 
        _instance = new MPCController;
    return _instance;
}

/* CONSTRUCTOR */
MPCController::MPCController() {
    midi = MidiController::Instance();

    // Add a drumpad object for each preset drumpad id code
    int padNumber = 0;

    for (int id_code : MPC_CONSTANTS::DRUMPAD_IDENTIFIERS) {
        DrumPad drumpad { id_code, padNumber };
        drumpads.push_back(drumpad);
        input_map[id_code] = (Input*) &drumpads.back();
        padNumber++;
    }
};

/* MEMBER FUNCTIONS */
void MPCController::Boot() {

    // Set initial colour of drumpads
    float percent = 0;
    float step = 1.0 / 16.0; 
    for (DrumPad pad : drumpads) {
        int fade = 127 * percent;
        pad.setLightColour(RGB(127, fade, fade));
        percent += step;
    }

    while (true) {}
};

// void MPCController::HandleMidiMessage(libremidi::message message) {

// };
