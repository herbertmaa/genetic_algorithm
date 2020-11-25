//
// Created by Yogesh Verma on 2020-11-24.
//

#include "catch2/catch.hpp"
#include "../headers/CityList.hpp"

constexpr double CITIES_IN_TOUR = CityList::CITIES_IN_TOUR;

TEST_CASE("A CityList must create a list of CITIES_IN_TOUR cities", "GetInstance") {
    CityList& c = CityList::get_instance();

    vector<City* > result = c.shuffle();
    CHECK(result.size() == CITIES_IN_TOUR);
}

TEST_CASE("Can shuffle cities around", "Shuffle") {
    CityList& c = CityList::get_instance();

    vector<City* > result = c.shuffle();
    vector<City* > result2 = c.shuffle();
    CHECK(result != result2);
}
