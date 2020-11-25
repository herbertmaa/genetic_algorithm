#include <iostream>
#include "headers/GeneticAlgorithm.hpp"
#include "headers/CityList.hpp"
#include <algorithm>    // std::find
#include <cmath>

#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

using namespace std;

void test_tour_manager();
void test_shuffle();
void test_get_distance_between_cities();
void test_equality_cities();
void test_assignment_cities();
void test_city_copy();
void test_tour_mutate();

int main(int argc, char *argv[]) {
    int result;

    try {
        // bootstrap Catch, running all TEST_CASE sequences.
        result = Catch::Session().run(argc, argv);
    } catch (const std::exception& ex) {
        auto pMessage = ex.what();
        if (pMessage) {
            std::cout << "An unhandled exception was thrown:\n" << pMessage;
        }
        std::cin.get(); // Immediate feedback.
        return -1;
    }

//    GeneticAlgorithm g{};
//    test_shuffle();
//    test_get_distance_between_cities();
//    test_equality_cities();
//    test_assignment_cities();
//    test_city_copy();
    return result;
}

void test_tour_manager(){
    ToursManager manager;
    manager.print_tours();
}
