#include <iostream>
#include "headers/GeneticAlgorithm.hpp"
#include "headers/CityList.hpp"

using namespace std;

void test_tour();

int main() {
    GeneticAlgorithm g{};
    cout << g;

//    test_tour();
    return 0;
}

void test_tour() {
    Tour tour {};
    cout << tour << endl;
    tour.mutation();
    cout << tour << endl;
}

