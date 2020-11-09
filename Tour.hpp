//
// Created by Herbert Ma on 2020-11-07.
//

#pragma once

#include "City.hpp"
#include <vector>

using std::ostream;

class Tour {
private:
    double improvement_factor;
    std::vector<City* > cities;
    int sequence_number = 0;
    double fitness = 0;
public:
    Tour(int num_cities);
    Tour(const Tour&t);
    void shuffle_cities();
    void determine_fitness();
    void select_parents();
    bool contains_city(City* city);
    inline double get_fitness() const {return this->fitness;};
    inline void update_fitness(double new_fitness) { this->fitness = new_fitness;};
    friend ostream&operator <<(ostream&os, const Tour& t);
};

