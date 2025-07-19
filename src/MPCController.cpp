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
    std::function<void (libremidi::message message)> callback = [this](libremidi::message message) { this->MidiCallback(message); };
    midi->setCallbackFunction(callback);

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

void MPCController::MidiCallback(libremidi::message message) {
    for (auto byte : message.bytes) {
        std::cout << std::hex << std::setw(2) << (int)byte << "(" << std::dec << (int)byte << ")" << " ";
    }
    std::cout << std::endl;
}