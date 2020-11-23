//
// Created by Yogesh Verma on 2020-11-22.
//

#pragma once

#include <vector>
#include "City.hpp"

using std::vector;

class CityList {
private:
    static CityList *instance;
    vector<City *> cities;
    CityList() = default;

public:
    static constexpr int RANDOM_SEED = 37;
    static constexpr int CITIES_IN_TOUR = 10;
    /**
    * Prevents assignment of the instance
    */
    void operator=(CityList const &) = delete;
    /**
     * Gets the singleton instance
     * @return a pointer to the global instance of CityList
     */
    static CityList *get_instance();
    /**
     * Deletes the global instance
     */
    static void reset_instance();
    ~CityList();
    vector<City *> shuffle() const;
};
