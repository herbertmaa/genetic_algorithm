//
// Created by Herbert Ma on 2020-11-07.
//

#include <random>
#include <algorithm>
#include <iostream>
#include "../headers/Tour.hpp"
#include "../headers/City.hpp"
#include "../headers/CityList.hpp"

using std::cout;
using std::endl;

constexpr int SHUFFLES = 64;
constexpr int ITERATIONS = 1000;
constexpr int MAP_BOUNDARY = 1000;
constexpr int PARENT_POOL_SIZE = 5;
constexpr double MUTATION_RATE = 0.15;
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
}

ostream &operator<<(ostream &os, const Tour &t) {

    for (auto it = t.cities.begin(); it != t.cities.end(); ++it) {
        os << **it;
    }
    return os;
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
    std::random_device rd;
    std::uniform_int_distribution<int> d(0, cities.size() - 1);
    auto it = cities.begin() + d(rd);
    auto it2 = cities.begin() + d(rd);
    std::iter_swap(it, it2);
    this->fitness = determine_fitness();
}

Tour &Tour::operator=(Tour assignment) {
    cities = assignment.cities; // assigns all pointers in deque to point to the values in assignment.cities
    fitness = assignment.fitness; // assigns the fitness of the tour to the fitness of the assignment tour
    return *this;
}

void Tour::gen_random_cities() {
    std::random_device rd;
    std::mt19937 eng{rd()};
    std::uniform_int_distribution<int> dist{0, CityList::CITIES_IN_TOUR - 1};
    for (int i = 0; i < CityList::CITIES_IN_TOUR; i++) {
        int rand = dist(eng);
        ++sequence_number;
        cities.push_back(CityList::get_instance()->get_city(rand));
    }
}

Tour::~Tour() {
    for (auto it = cities.begin(); it != cities.end(); ++it) {
        *it = nullptr;
    }
}
