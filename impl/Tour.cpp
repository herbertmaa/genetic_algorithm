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
using std::swap;


Tour::Tour() {
    cities = CityList::get_instance().shuffle();
    determine_fitness();
}

Tour::Tour(const Tour &t1, const Tour &t2) {

    std::mt19937 e{std::random_device{}()};
    std::uniform_int_distribution<int> dist{0, CityList::CITIES_IN_TOUR -1};

    int rand = dist(e);

    // Get a end point of the Tour 1 to copy from
    auto end = t1.cities.begin() + rand;

    // Copy from the beginning to the end of the tour
    for(auto it = t1.cities.begin(); it <= end; ++it){
        cities.push_back(*it);
    }

    // Fill in the rest of cities vector with cities from T2
    for(auto city : t2.cities) {

        //If the city is already in T1, do not push into it.
        if (!contains_city(city)) {
            cities.push_back(city);
        }
    }

    //Determine the fitness of the newly created tour
    determine_fitness();
}

Tour::Tour(const Tour &t) {
    cities = vector<City *> {t.cities.begin(), t.cities.end()};
    fitness = t.fitness;
    total_distance = t.total_distance;
    determine_fitness();
}

void Tour::swap(Tour &lhs, Tour &rhs) {

    lhs.cities.swap(rhs.cities);
    std::swap(lhs.fitness, rhs.fitness);
    std::swap(lhs.total_distance, rhs.total_distance);
}

ostream &operator<<(ostream &os, const Tour &t) {
    os << "Tour distance: " << t.get_tour_distance() << endl;
    os << "Tour fitness: " << t.get_fitness() << endl;
    for(City* c: t.cities){
        os << *c << endl;
    }
    return os;
}

void Tour::determine_fitness() {
    total_distance = 0;
    for (auto it = cities.begin(); it != cities.end() - 1; ++it) {
        total_distance += get_distance_between_cities(**it, **(it + 1));
    }
    if (total_distance == 0) throw std::invalid_argument("DIVIDING BY ZERO");
    this-> fitness = Tour::RANDOM_SEED / total_distance;
}

bool Tour::operator<(const Tour &t2) const {
    return (this->fitness < t2.fitness);
}

void Tour::mutate() {
    // Random number generator
    std::mt19937 e{std::random_device{}()};
    std::uniform_real_distribution<double> dist(0, 1);

    // Get a random iterator pointing to a city in the tour
    // Random number
    for (int i = 0; i < (int) cities.size(); ++i) {
        int rand = dist(e);
        auto it = cities.begin() + i;

        if (rand > MUTATION_RATE) continue;

        // Check for cases of the iterator being at the beginning or the end
        if (it == cities.end() - 1) {
            iter_swap(it, it - 1);
        } else if (it == cities.begin()) {
            iter_swap(it, it + 1);
        } else if (rand < (MUTATION_RATE / 2)) {
            iter_swap(it, it - 1);
        } else {
            iter_swap(it, it + 1);
        }
    }

    // Redetermine the fitness of the tour
    determine_fitness();
}

Tour &Tour::operator=(Tour assignment) {
    swap(*this, assignment);
    return *this;
}

double Tour::get_fitness() const {
    if (fitness != 0) return fitness;
    throw std::overflow_error("Fitness value is equal to 0");
}

bool Tour::contains_city(City* city) const {
    if (std::find(cities.begin(), cities.end(), city) != cities.end()) {
        return true;
    } else {
        return false;
    }
}

int Tour::num_cities() const {
    return cities.size();
}
