cmake_minimum_required(VERSION 3.10)
project(Gomoku)

set(CMAKE_CXX_STANDARD 14)

add_executable(Gomoku main_gomoku.cpp gomoku.cpp judge.cpp start_program.cpp keyboard.cpp)

target_include_directories(Gomoku PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})