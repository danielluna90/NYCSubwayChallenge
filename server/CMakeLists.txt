cmake_minimum_required(VERSION 3.27)
project(NYCSubwayChallenge)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CORE_SRC src/core/core.h)
set(SUBSYSTEMS_SRC )
set(TERMINAL_SRC src/terminal/parser.cpp src/terminal/parser.h src/terminal/command.h src/terminal/commands.h)

add_executable(NYCSubwayChallenge src/main.cpp ${CORE_SRC} ${SUBSYSTEMS_SRC} ${TERMINAL_SRC})
