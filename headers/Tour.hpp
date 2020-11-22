//
// Created by Herbert Ma on 2020-11-07.
//

#pragma once

#include "City.hpp"
#include <vector>

using std::ostream;

class Tour {
private:
    double improvement_factor = 0;
    std::vector<City *> cities;

    int sequence_number = 0;
    double fitness = 0;
    double total_distance = 0;

    double determine_fitness();
    void gen_random_cities();

public:
    Tour();
    Tour(Tour * tours[2]);
    ~Tour();

    Tour& operator=(Tour assignment);
    bool contains_city(City* city);
    void mutation();

    inline int num_cities() const { return this->cities.size(); };
    inline double get_fitness() const {return this->fitness;};
    inline double get_total_distance() const {return this->total_distance;};
    friend ostream&operator <<(ostream&os, const Tour& t);
    bool operator < (const Tour& t2) const;

    friend bool operator <(const Tour& t1, const Tour& t2);
};

