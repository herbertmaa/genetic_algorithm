cmake_minimum_required(VERSION 3.17)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_executable(GeneticAlgorithm main.cpp impl/City.cpp headers/City.hpp impl/Tour.cpp headers/Tour.hpp impl/GeneticAlgorithm.cpp headers/CityList.hpp headers/ToursManager.hpp impl/CityList.cpp impl/ToursManager.cpp headers/GeneticAlgorithm.hpp)