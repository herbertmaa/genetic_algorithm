//
// Created by Yogesh Verma on 2020-11-22.
//

#pragma once

#include <vector>
#include "City.hpp"

using std::vector;

class CityList {
private:
    vector<City *> cities; // A vector to store list of cities
    CityList() = default; // Singleton object of CityList, so we have hidden the constructor
    ~CityList();

public:
    static constexpr int CITIES_IN_TOUR = 32;

    /* Delete the assignment operator to prevents assignment of the instance*/
    void operator=(CityList const &) = delete;
    /**
     * Gets the singleton instance
     * @return a reference to the global instance of CityList
     */
    static CityList& get_instance();

    /**
     * Getter function that gets a vector copy of the shuffled city list
     * @return - A shuffled city list
     */
    vector<City *> shuffle() const;
};
