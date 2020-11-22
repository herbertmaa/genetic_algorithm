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
    std::vector<City* > cities;
    int sequence_number = 0;
    double fitness = 0;
    double determine_fitness();
public:
    Tour(int num_cities);
    Tour() = default;
    Tour& operator=(Tour assignment);
    Tour(const Tour&t);
    void shuffle_cities();
    bool contains_city(City* city);
    void mutation();
    inline int num_cities() const { return this->cities.size(); };
    inline double get_fitness() const {return this->fitness;};
    friend ostream&operator <<(ostream&os, const Tour& t);
    constexpr static int CITIES_IN_TOURS = 10;
    bool operator < (const Tour& t2) const;
    void insert_city_front(City * city);
    void insert_city_back(City * city);

};

