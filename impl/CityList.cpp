//
// Created by Yogesh Verma on 2020-11-22.
//

#include <random>
#include <stdexcept>
#include <algorithm>
#include "../headers/CityList.hpp"


CityList &CityList::get_instance() {

    // Create only one instance inside this method. This is the instance that we will access.
    static CityList instance;

    //Initialize the cities within the Singleton object, this only happens once.
    if(instance.cities.empty()){
        std::mt19937 e{std::random_device{}()};
        std::uniform_int_distribution<int> dist{City::MIN_MAP_BOUNDARY, City::MAX_MAP_BOUNDARY};
        for (int i = 0; i < CITIES_IN_TOUR; ++i) {
            instance.cities.push_back(new City(dist(e), dist(e), "C" + std::to_string(i)));
        }
    }
    return instance;
}

CityList::~CityList() {

    // Deallocate City memory that was made when we created the instance of the Singleton
    for (auto it = cities.begin(); it != cities.end(); it++) {
        delete (*it);
    }
}


vector<City *> CityList::shuffle() const {
    // Create a copy of the cities currently in the Singleton
    vector<City *> copy_cities = cities;

    // Use STL shuffle to shuffle the copy
    std::mt19937 e{std::random_device{}()};
    std::shuffle(copy_cities.begin(), copy_cities.end(), e);

    return copy_cities;
}
