cmake_minimum_required(VERSION 4.00)
project (mpc)

add_subdirectory(3rdparty/libremidi)

add_executable(${PROJECT_NAME} src/main.cpp src/MPC.cpp src/miniaudio.c src/AudioController.cpp src/BaseInput.cpp src/Utility.cpp src/RGB.cpp src/DrumPad.cpp src/Button.h src/BaseMidi.cpp src/MidiSender.cpp src/MidiReceiver.cpp src/DefaultState.cpp src/MPCState.cpp src/DrumPadRequest.h src/ButtonRequest.h src/CopyPasteSoundState.cpp src/commands/MPCCommand.h src/commands/CopyPasteSoundCommand.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE libremidi)
