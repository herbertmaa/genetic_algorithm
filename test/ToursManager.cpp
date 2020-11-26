//
// Created by Yogesh Verma on 2020-11-25.
//

#include "catch2/catch.hpp"
#include "../headers/ToursManager.hpp"
#include "../headers/CityList.hpp"

constexpr double CITIES_IN_TOUR = CityList::CITIES_IN_TOUR;

TEST_CASE("Construct a tours manager", "DefaultConstruct") {
    ToursManager toursManager;
    CHECK(toursManager.get_elite_distance() < (CITIES_IN_TOUR * City::MAX_MAP_BOUNDARY));
    CHECK(toursManager.get_elite_fitness() < 1);
}
