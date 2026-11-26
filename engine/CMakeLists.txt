
cmake_minimum_required(VERSION 3.20)

project(VantaEngine
    VERSION 0.1.0
    DESCRIPTION "Vanta Native Game Trainer Engine"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(vanta-engine
    src/main.cpp
    src/steam/VdfParser.cpp
    src/steam/SteamScanner.cpp
)

target_include_directories(vanta-engine
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(WIN32)
    target_compile_definitions(vanta-engine PRIVATE VANTA_PLATFORM_WINDOWS)
elseif(UNIX)
    target_compile_definitions(vanta-engine PRIVATE VANTA_PLATFORM_LINUX)
endif()

if(MSVC)
    target_compile_options(vanta-engine PRIVATE /W4)
else()
    target_compile_options(vanta-engine PRIVATE -Wall -Wextra -Wpedantic)
endif()
