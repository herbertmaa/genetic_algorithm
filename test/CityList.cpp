//
// Created by Yogesh Verma on 2020-11-24.
//

#include "catch2/catch.hpp"
#include "../headers/CityList.hpp"

TEST_CASE("A CityList must create a list of 30 cities", "GetInstance") {
    CityList& c = CityList::get_instance();

    vector<City* > result = c.shuffle();
    CHECK(result.size() == 30);
}

TEST_CASE("Can shuffle cities around", "Shuffle") {
    CityList& c = CityList::get_instance();

    vector<City* > result = c.shuffle();
    vector<City* > result2 = c.shuffle();
    CHECK(result != result2);
}
