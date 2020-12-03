cmake_minimum_required(VERSION 3.0)

project (BreakoutGL)

file(GLOB SOURCE "src/**.cpp")

set(GAME "game")

add_executable(${GAME} ${SOURCE})

set_target_properties(${GAME} PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")