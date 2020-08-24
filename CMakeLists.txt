cmake_minimum_required(VERSION 3.10)
project(HangmanGame)
set(CMAKE_CXX_STANDARD 14)
add_executable(HangmanGame fun.cpp word.cpp wordList.cpp game.cpp main.cpp)