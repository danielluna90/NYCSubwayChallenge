cmake_minimum_required(VERSION 3.27)
project(NYCSubwayChallenge)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CORE_SRC src/core/core.cpp src/core/core.h)

set(API_SUBSYSTEM_SRC src/subsystems/api/api.h)

set(SUBSYSTEMS_SRC src/subsystems/subsystem.h src/subsystems/subsystems.h
                   src/subsystems/manager.cpp src/subsystems/manager.h
                   ${API_SUBSYSTEM_SRC})

set(TERMINAL_SRC src/terminal/command.h src/terminal/parser.cpp src/terminal/parser.h src/terminal/terminal.h)

add_executable(NYCSubwayChallenge src/main.cpp ${CORE_SRC} ${SUBSYSTEMS_SRC} ${TERMINAL_SRC})
