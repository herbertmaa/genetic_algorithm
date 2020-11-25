#include <iostream>
#include "headers/GeneticAlgorithm.hpp"
#include "headers/CityList.hpp"

using namespace std;

void test_tour();
void test_tourManager();

int main() {
    GeneticAlgorithm g{};
    cout << g;
    return 0;
}

void test_tour() {
    Tour tour {};
    cout << tour << endl;
    tour.mutation();
    cout << tour << endl;
}


void test_tourManager(){
    ToursManager manager;
    manager.print_tours();
}