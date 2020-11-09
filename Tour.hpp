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
    double determine_fitness();
public:
    Tour(int num_cities);
    Tour(const Tour&t);
    void shuffle_cities();
    void select_parents();
    bool contains_city(City* city);
    void mutation();
    inline double get_fitness() const {return this->fitness;};
    friend ostream&operator <<(ostream&os, const Tour& t);
    constexpr static int CITIES_IN_TOURS = 10;
    friend bool operator <(const Tour& t1, const Tour& t2);
};

