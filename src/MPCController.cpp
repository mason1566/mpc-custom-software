#include "MPCController.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <libremidi/libremidi.hpp>

void MPCController::HandleMidiMessage(libremidi::message message) {

}

MPCController::MPCController() {
    auto callback = [this](libremidi::message&& message) {
        this->HandleMidiMessage(message);
    };

    midi_in = std::make_unique<libremidi::midi_in>(
        libremidi::input_configuration{ .on_message = callback }
    );
};

void MPCController::Boot() {

};

