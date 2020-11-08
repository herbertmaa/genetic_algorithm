//
// Created by Herbert Ma on 2020-11-07.
//

#include <random>
#include "Tour.hpp"
#include <iostream>

using std::cout;
using std::endl;

constexpr int RANDOM_SEED = 37;
constexpr int SHUFFLES = 64;
constexpr int ITERATIONS = 1000;
constexpr int MAP_BOUNDARY = 1000;
constexpr int PARENT_POOL_SIZE = 5;
constexpr double MUTATION_RATE = 0.15;
constexpr int NUMBER_OF_PARENTS = 1; //TODO ? What is this used for ?
constexpr int NUMBER_OF_ELITES = 1;

Tour::Tour(int num_cities) {

    std::mt19937 eng{RANDOM_SEED};
    std::uniform_int_distribution<int> dist{City::min_range, City::max_range};

    for(int i = 0; i < num_cities; i++){
        City* c = new City(dist(eng), dist(eng), "C" + std::to_string(sequence_number));
        ++sequence_number;
        cities.push_back(c);
    }
}

ostream &operator<<(ostream &os, const Tour &t) {

    for(auto it = t.cities.begin(); it != t.cities.end(); ++it){
        std::cout << **it;
    }
}
