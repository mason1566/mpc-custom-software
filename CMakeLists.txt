cmake_minimum_required(VERSION 4.00)
project (mpc)

add_subdirectory(3rdparty/libremidi)

add_executable(${PROJECT_NAME} src/main.cpp src/MPC.cpp src/miniaudio.c src/AudioController.cpp src/Input.cpp src/Utility.cpp src/RGB.cpp src/DrumPad.cpp src/Button.h src/MidiController.cpp src/MPCState.h src/CopyPasteSoundState.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE libremidi)
