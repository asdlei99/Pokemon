cmake_minimum_required(VERSION 3.19)
project(PokemonPP)

set(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(SDL/include)
LINK_DIRECTORIES(SDL/lib/x64)
add_executable(PokemonPP WIN32 main.cpp)
TARGET_LINK_LIBRARIES(PokemonPP SDL2main.lib SDL2.lib)