#ifndef INPUT_MANAGER
#define INPUT_MANAGER

#include "BaseInput.h"
#include "Button.h"
#include "DrumPad.h"
#include "InputEvent.h"
#include "../states/StateManager.h"

#include <libremidi/libremidi.hpp>
#include <unordered_map>

// Holds:
//   - References to input devices (DrumPad, Button, etc.).
//   - Reference to StateManager (to dispatch input events).
// Receives MIDI messages via callback from MidiReceiver.
// Converts MIDI to InputEvent.
// Forwards events to StateManager via: "stateManager.handleInput(InputEvent e);""
class InputManager {
public:
    // Member Variables
    std::vector<Button> buttons;
    std::vector<DrumPad> drumpads;
    std::unordered_map<int, BaseInput*> input_map;
    std::unordered_map<int, Button*> button_map;
    std::unordered_map<int, DrumPad*> drum_map;

    // Member Functions
    void handleMidiMessage(const libremidi::message& message);

    // Constructor
    InputManager(StateManager& stateManager);
protected:
    StateManager& stateManager;
    
    void setupDrumPads();
    void setupButtons();
};

#endif