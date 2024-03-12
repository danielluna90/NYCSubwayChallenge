cmake_minimum_required(VERSION 3.27)
project(NYCSubwayChallenge)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CORE_SRC src/core/core.cpp)

set(API_SUBSYSTEM_SRC )

set(SUBSYSTEMS_SRC src/subsystems/manager.cpp ${API_SUBSYSTEM_SRC})

set(TERMINAL_SRC src/terminal/parser.cpp)

add_executable(NYCSubwayChallenge src/main.cpp ${CORE_SRC} ${SUBSYSTEMS_SRC} ${TERMINAL_SRC})
target_include_directories(NYCSubwayChallenge PRIVATE src)
