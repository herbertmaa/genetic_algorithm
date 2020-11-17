cmake_minimum_required(VERSION 3.17)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)

add_executable(GeneticAlgorithm main.cpp impl/City.cpp headers/City.hpp impl/Tour.cpp headers/Tour.hpp impl/GeneticAlgorithm.cpp headers/GeneticAlgorithm.hpp test/City.cpp)

target_link_libraries(GeneticAlgorithm Catch2::Catch2)