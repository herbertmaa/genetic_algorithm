//
// Created by Herbert Ma on 2020-11-07.
//

#include <random>
#include "Tour.hpp"
#include <iostream>
#include <algorithm>

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

void Tour::shuffle_cities() {
    auto rng = std::default_random_engine {};
    rng.seed(time(nullptr));
    std::shuffle(cities.begin(), cities.end(), rng);
}


Tour::Tour(const Tour &t) {
    for(auto it = t.cities.begin(); it != t.cities.end(); ++it){
        cities.push_back((*it));
    }
    fitness = t.fitness;
}

void Tour::determine_fitness() {
    if(fitness == 0){
        throw std::invalid_argument("Fitness value is 0 or has not been calculated.");
    }
    this->fitness = 1 / fitness * RANDOM_SEED;
}

