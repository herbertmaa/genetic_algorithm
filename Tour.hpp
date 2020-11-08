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
public:
    Tour(int num_cities);
    void shuffle_cities();
    void get_distance_between_cities();
    void determine_fitness();
    void select_parents();
    bool contains_city(City* city);
    friend ostream&operator <<(ostream&os, const Tour& t);
};

