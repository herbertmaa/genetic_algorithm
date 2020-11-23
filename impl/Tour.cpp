//
// Created by Herbert Ma on 2020-11-07.
//

#include <random>
#include <algorithm>
#include <iostream>
#include "../headers/Tour.hpp"
#include "../headers/CityList.hpp"

using std::cout;
using std::endl;

constexpr int SHUFFLES = 64;
constexpr int MAP_BOUNDARY = 1000;
constexpr int PARENT_POOL_SIZE = 5;
constexpr int NUMBER_OF_ELITES = 1;

Tour::Tour() {
    gen_random_cities();
    this->fitness = determine_fitness();
}

Tour::Tour(Tour **tours) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < CityList::CITIES_IN_TOUR; ++j) {
            City * to_add = tours[i]->cities.at(j);
            if (std::find(cities.begin(), cities.end(), to_add) != cities.end()) {
                cities.push_back(to_add);
            }
        }
    }
    this->fitness=determine_fitness();
}

ostream &operator<<(ostream &os, const Tour &t) {
    os << "TODO remove this print out, in Tour.cpp" << endl;
    os << t.get_total_distance() << endl;
    os << t.get_fitness() << endl;
    for (auto it = t.cities.begin(); it != t.cities.end(); ++it) {
        os << **it;
    }
    return os;
}

Tour::Tour(const Tour &t) {
    for (auto it = t.cities.begin(); it != t.cities.end(); ++it) {
        cities.push_back((*it));
    }
    this->fitness = determine_fitness();
}

double Tour::determine_fitness() {
    total_distance = 0;
    for (auto it = cities.begin(); it != cities.end() - 1; ++it) {
        total_distance += get_distance_between_cities(**it, **(it + 1));
    }
    if (total_distance == 0) throw std::invalid_argument("DIVIDING BY ZERO");
    return 1 / total_distance * CityList::RANDOM_SEED;
}

bool Tour::operator<(const Tour &t2) const {
    return (this->fitness < t2.fitness);
}

void Tour::mutation() {

    // Random number generator
    std::mt19937 e{std::random_device{}()};
    std::uniform_int_distribution<int> dist(0, cities.size() - 1);

    // Get a random iterator pointing to a city in the tour

    // Random number
    int rand = dist(e);
    auto it = cities.begin() + rand;

    // Check for cases of the iterator being at the beginning or the end
    if (it == cities.end() - 1) {
        iter_swap(it, it - 1);
    } else if (it == cities.begin()) {
        iter_swap(it, it + 1);
    } else if (rand % 2) {
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

double Tour::get_fitness() const {

    if (fitness != 0) {
        return  CityList::RANDOM_SEED / fitness;
    }
    throw std::overflow_error("Fitness value is equal to 0");
}

void Tour::gen_random_cities() {
    cities = CityList::get_instance()->shuffle();
}

Tour::~Tour() {
    cities.clear();
}
