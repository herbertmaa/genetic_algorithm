//
// Created by Herbert Ma on 2020-11-07.
//

#include <random>
#include "Tour.hpp"
#include "City.hpp"
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
    this->fitness = determine_fitness();
}

ostream &operator<<(ostream &os, const Tour &t) {

    for(auto it = t.cities.begin(); it != t.cities.end(); ++it){
        os << **it;
    }
    return os;
}

void Tour::shuffle_cities() {
    std::random_shuffle(cities.begin(), cities.end());
    this->fitness = determine_fitness();
}


Tour::Tour(const Tour &t) {
    for(auto it = t.cities.begin(); it != t.cities.end(); ++it){
        cities.push_back((*it));
    }
    this->fitness = determine_fitness();
}

double Tour::determine_fitness() {
    double total_distance = 0;
    for(auto it = cities.begin(); it != cities.end()-1; ++it){
        total_distance = get_distance_between_cities(**it, **(it+1));
    }
    return 1 / total_distance * RANDOM_SEED;
}

bool operator<(const Tour &t1, const Tour &t2) {
    return (t1.fitness < t2.fitness);
}

void Tour::mutation() {
    std::random_device rd;
    std::uniform_int_distribution<int> d(0, cities.size() - 1);
    auto it = cities.begin() + d(rd);
    auto it2 = cities.begin() + d(rd);
    std::iter_swap(it, it2);
}

