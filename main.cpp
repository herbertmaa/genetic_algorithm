#include <iostream>
#include "headers/GeneticAlgorithm.hpp"
#include "headers/CityList.hpp"

using namespace std;

void test_city();
void test_tour();
void test_tour_manager();
void test_genetic_algorithm();
void test_city_list();

int main() {
    GeneticAlgorithm g{};
    cout << g;
    return 0;
}