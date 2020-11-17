//
// Created by Yogesh Verma on 2020-11-16.
//

#include "catch2/catch.hpp"
#include "../headers/City.hpp"

TEST_CASE("Gets the name of the city", "[City][get_name]") {
    City city1 {0, 3, "CityA"};
    CHECK(city1.get_name() == "CityA");
}

