#include "MPC.h"

/* SINGLETON INSTANCE IMPLEMENTATION */
MPC* MPC::_instance = nullptr;

MPC* MPC::Instance() {
    if (!_instance) 
        _instance = new MPC;
    return _instance;
}

/* CONSTRUCTOR */
MPC::MPC() : midiSend(MidiSender::instance()), 
             midiReceive(MidiReceiver::instance()),
             audio(AudioController::instance()),
             inputManager(),
             stateManager(audio, midiSend, inputManager)
{
    // midiSend = MidiSender::instance();
    // midiReceive = MidiReceiver::instance();
    // audio = AudioController::instance();
    // stateManager = StateManager::instance();
    // commandProcessor = CommandProcessor::instance();
    // inputManager = InputManager::instance();
    // StateManager& stateManager { audio, midiSend, inputManager };

    midiReceive.setMidiCallbackFunction([&](const libremidi::message& message) {
        // std::cout << "Wiring midi events!\n";
        inputManager.handleMidiMessage(message);
    });

    inputManager.setInputEventCallback([&](const InputEvent& inputEvent) {
        // std::cout << "Wiring input events!\n";
        stateManager.handleEvent(inputEvent);
    });
    // auto midiCallback = [this](MidiInputSignal message) { HandleMidiMessage(message); };
    // midi_receive->setMidiCallbackFunction(midiCallback);

    // Set the state
    // stateStack.push((MPCState*) new DefaultState());

    // Turn on Pad Mute Button light
    // unsigned char message[] { MPC_CONSTANTS::MIDI_MESSAGES::MIDI_CONTROL_CHANGE, 4, 3 };
    // midi->midi_out.send_message(message, sizeof(message));
};

/* MEMBER FUNCTIONS */
void MPC::Boot() {
    // Set initial colour of drumpads
    // for (int i = 0; i < drumpads.size(); i++) {
    //     drumpads[i].setLightOff();
    //     midi_send->setPadRGB(i, drumpads[i].getLightColour());
    // }

    while (true) {

    }
};

// void MPC::HandleMidiMessage(MidiInputSignal midiSignal) {
//     std::cout << midiSignal.midiValue << std::endl;

    // if (stateStack.top()) {
    //     if (midiSignal.inputType == InputType::DRUMPAD_INPUT) {
    //         currentDrumpad = drum_map[midiSignal.midiValue];
    //         DrumPadRequest request { currentDrumpad, midiSignal };
    //         stateStack.top()->handleRequest(request);
    //     }
    //     else if (midiSignal.inputType == InputType::BUTTON_INPUT) {

    //     }

        // switch (midiSignal.signalCode) 
        // {
        // case MIDI_INPUT_SIGNALS::DRUMPAD_DOWN:
        //     currentDrumpad = drum_map[midiSignal.midiValue];
        //     currentDrumpad->velocity = midiSignal.velocity;
        //     currentState->handleRequest(DrumPadRequest(currentDrumpad, DrumPadSignal::DRUMPAD_DOWN));
        //     break;
        // case MIDI_INPUT_SIGNALS::BUTTON_DOWN:
        //     currentState->handleRequest(ButtonRequest(button_map[midiSignal.midiValue], ButtonSignal::BUTTON_DOWN));
        //     break;
        // default:
        //     break;
        // }
    // }
// };


