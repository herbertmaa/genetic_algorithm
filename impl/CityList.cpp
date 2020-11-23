//
// Created by Yogesh Verma on 2020-11-22.
//

#include <random>
#include <stdexcept>
#include "../headers/CityList.hpp"

CityList * CityList::instance = nullptr;

CityList * CityList::get_instance() {
    if (!CityList::instance) {
        CityList::instance = new CityList{};

        std::mt19937 eng{RANDOM_SEED};
        std::uniform_int_distribution<int> dist{City::MIN_RANGE, City::MAX_RANGE};
        for (int i = 0; i < CITIES_IN_TOUR; ++i) {
            CityList::instance->cities.push_back(new City(dist(eng), dist(eng), "C" + std::to_string(i)));
        }
    }
    return CityList::instance;
}

void CityList::reset_instance() {
    delete instance;
    CityList::instance = nullptr;
}

City * CityList::get_city(int n) {
    get_instance();
    if (n < 0 || n > instance->cities.size() - 1) {
        throw std::invalid_argument("Invalid index");
    }
    return instance->cities.at(n);
}

CityList::~CityList() {
    for (auto it = cities.begin(); it != cities.end(); it++) {
        delete (*it);
    }
}


