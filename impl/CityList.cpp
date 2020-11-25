//
// Created by Yogesh Verma on 2020-11-22.
//

#include <random>
#include <stdexcept>
#include <algorithm>
#include "../headers/CityList.hpp"


CityList &CityList::get_instance() {

    // Create only one instance inside this method. This is the instance that we will access. FOREVER.
    static CityList instance;

    if(instance.cities.empty()){
        std::mt19937 eng{RANDOM_SEED};
        std::uniform_int_distribution<int> dist{City::MIN_RANGE, City::MAX_RANGE};
        for (int i = 0; i < CITIES_IN_TOUR; ++i) {
            instance.cities.push_back(new City(dist(eng), dist(eng), "C" + std::to_string(i)));
        }
    }
    return instance;
}

CityList::~CityList() {
    for (auto it = cities.begin(); it != cities.end(); it++) {
        delete (*it);
    }
}


vector<City *> CityList::shuffle() const {
    vector<City *> copy_cities = cities;
    std::mt19937 e{std::random_device{}()};
    std::shuffle(copy_cities.begin(), copy_cities.end(), e);
    return copy_cities;
}
