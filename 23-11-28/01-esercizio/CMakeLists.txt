cmake_minimum_required(VERSION 3.27)
project(01_esercizio)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(01_esercizio
        esercizio1.cc
        esercizio1.h
        esercizio1_main.cc)
