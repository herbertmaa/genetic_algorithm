//
// Created by Herbert Ma on 2020-11-07.
//

#include <random>
#include "../headers/Tour.hpp"
#include "../headers/City.hpp"
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;

constexpr int RANDOM_SEED = 37;
constexpr int SHUFFLES = 64;
constexpr int ITERATIONS = 1000;
constexpr int MAP_BOUNDARY = 1000;
constexpr int PARENT_POOL_SIZE = 5;
constexpr double MUTATION_RATE = 0.15;
constexpr int NUMBER_OF_ELITES = 1;

Tour::Tour(int num_cities) {
    std::mt19937 e{std::random_device{}()};
    std::uniform_int_distribution<int> dist{City::min_range, City::max_range};

    for (int i = 0; i < num_cities; i++) {
        City *c = new City(dist(e), dist(e), "C" + std::to_string(sequence_number));
        ++sequence_number;
        cities.push_back(c);
    }
    this->fitness = determine_fitness();
}

ostream &operator<<(ostream &os, const Tour &t) {

    for (auto it = t.cities.begin(); it != t.cities.end(); ++it) {
        os << **it;
    }
    return os;
}

void Tour::shuffle_cities() {
    std::random_shuffle(cities.begin(), cities.end());
    this->fitness = determine_fitness();
}

Tour::Tour(const Tour &t) {
    for (auto it = t.cities.begin(); it != t.cities.end(); ++it) {
        cities.push_back((*it));
    }
    this->fitness = determine_fitness();
}

double Tour::determine_fitness() {
    double total_distance = 0;
    for (auto it = cities.begin(); it != cities.end() - 1; ++it) {
        total_distance = get_distance_between_cities(**it, **(it + 1));
    }

    if (total_distance == 0) throw std::invalid_argument("DIVIDING BY ZERO");

    return 1 / total_distance * RANDOM_SEED;
}

bool Tour::operator<(const Tour &t2) const {
    return (this->fitness < t2.fitness);
}

void Tour::mutation() {


    // Random number generator
    std::mt19937 e{std::random_device{}()};
    std::uniform_int_distribution<int> dist(0, cities.size() - 1);

    // Get a random iterator pointing to a city in the tour
    auto it = cities.begin() + dist(e);

    // If the random iterator is at the end, swap it with the element right before it
    if (it == cities.end() - 1) {
        iter_swap(it, it - 1);
    } else {
        iter_swap(it, it + 1);
    }

    // Redetermine the fitness of the tour
    this->fitness = determine_fitness();
}

Tour &Tour::operator=(Tour assignment) {
    cities = assignment.cities; // assigns all pointers in deque to point to the values in assignment.cities
    fitness = assignment.fitness; // assigns the fitness of the tour to the fitness of the assignment tour
    return *this;
}

double Tour::getDistance() const {

    if (fitness != 0) {
        return RANDOM_SEED / fitness;
    }
    throw std::overflow_error("Fitness value is equal to 0");
}


