cmake_minimum_required(VERSION 4.00)
project (mpc)

add_subdirectory(3rdparty/libremidi)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE libremidi)
