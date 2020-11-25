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
    double fitness = 0;
    double total_distance = 0;
    void determine_fitness();
    void gen_random_cities();
    void swap(Tour& lhs, Tour& rhs);

public:
    constexpr static double MUTATION_RATE = 0.5;

    Tour();
    Tour(const Tour& rhs);
    Tour(const Tour& t1, const Tour& t2);
    ~Tour();
    Tour& operator=(Tour assignment);
    bool contains_city(City* city);
    void mutate();
    inline int num_cities() const { return this->cities.size(); };
    double get_fitness() const;
    inline double get_tour_distance() const {return this->total_distance;};
    friend ostream&operator <<(ostream&os, const Tour& t);
    bool operator < (const Tour& t2) const;

};

