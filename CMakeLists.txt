cmake_minimum_required(VERSION 3.16.5)
project(tictactoe_sim)

set(CMAKE_CXX_STANDARD 14)

add_executable(tictactoe_sim src/main.cpp src/Board.cpp src/Player.cpp src/GameManager.cpp)