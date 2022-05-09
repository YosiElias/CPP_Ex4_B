cmake_minimum_required(VERSION 3.21)
project(Part_B)

set(CMAKE_CXX_STANDARD 14)

add_executable(Part_B main.cpp sources/Action.hpp sources/Ambassador.cpp sources/Ambassador.hpp sources/Assassin.cpp sources/Assassin.hpp sources/Captain.cpp sources/Captain.hpp sources/Contessa.cpp sources/Contessa.hpp sources/Duke.cpp sources/Duke.hpp sources/Game.cpp sources/Game.hpp sources/Player.cpp sources/Player.hpp)
