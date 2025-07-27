cmake_minimum_required(VERSION 4.00)
project (mpc)

add_subdirectory(3rdparty/libremidi)

add_executable(${PROJECT_NAME} 
    src/main.cpp 
    src/MPC.cpp

    # AUDIO
    src/audio/miniaudio.c 
    src/audio/AudioController.cpp 
    src/sounds/Sound.cpp

    # INPUT
    src/input/InputManager.cpp
    src/input/BaseInput.cpp 
    src/input/DrumPad.cpp 
    src/input/Button.h 
    src/input/InputEvent.h

    # UTILITY
    src/utility/Utility.cpp 
    src/utility/RGB.cpp 

    # MIDI
    src/midi/BaseMidi.cpp 
    src/midi/MidiSender.cpp 
    src/midi/MidiReceiver.cpp 

    # STATES
    src/states/StateManager.cpp
    src/states/State.cpp 
    src/states/DefaultState.cpp
    src/states/CopyPasteRGBState.cpp
    src/states/TurnOnAllPadsState.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE libremidi)
