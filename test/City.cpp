//
// Created by Yogesh Verma on 2020-11-16.
//

#include "../headers/City.hpp"
#include "catch2/catch.hpp"

TEST_CASE("Constructing a city with coordinates out of map boundary", "CheckCoords") {
    CHECK_THROWS(City {100000, 10000, "Invalid"});
}

TEST_CASE("Copy constructor of City", "Copy") {
    City c{49, 123, "Vancouver"};
    City c2{c};

    CHECK(c2 == c);
}

TEST_CASE("Two cities with same member variables must be equal", "Equals") {
    City c{49, 123, "Vancouver"};
    City c2{49, 123, "Vancouver"};
    CHECK(c == c2);
}

TEST_CASE("A city can be assigned to another", "Assignment") {
    City c{49, 123, "Vancouver"};
    City c2{19, 73, "mumbai"};
    c2 = c;
    CHECK(c2 == c);
}

TEST_CASE("Get distance between two cities", "GetDistance") {
    City c{49,123, "Vancouver"};
    City c2{19, 73, "mumbai"};

    double func_answer = get_distance_between_cities(c, c2);
    double answer = sqrt(pow((49-19), 2) + pow((123-73), 2));

    CHECK(func_answer == answer);
}

