#include <iostream>
#include "headers/GeneticAlgorithm.hpp"
#include "headers/CityList.hpp"

using namespace std;

int main() {
    GeneticAlgorithm g{};
    cout << g;
    CityList::reset_instance();
    return 0;
}
