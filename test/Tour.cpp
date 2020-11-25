//
// Created by Yogesh Verma on 2020-11-24.
//

#include "catch2/catch.hpp"
#include "../headers/Tour.hpp"
#include "../headers/CityList.hpp"

constexpr double CITIES_IN_TOUR = CityList::CITIES_IN_TOUR;

TEST_CASE("Construct a tour", "DefaultConstruct") {
    Tour tour;
    CHECK(tour.num_cities() == CITIES_IN_TOUR);
}

TEST_CASE("Construct a tour using copy constructor", "CopyConstruct") {
    Tour tour;
    Tour tour2{tour};
    CHECK(tour2.num_cities() == CITIES_IN_TOUR);
}

TEST_CASE("Construct a tour using cross constructor", "SwapConstruct") {
    Tour tour;
    Tour tour2{tour};
    Tour tour3{tour, tour2};
    CHECK(tour3.num_cities() == CITIES_IN_TOUR);
}

TEST_CASE("Assigning a tour to another", "Assignment") {
    Tour tour;
    Tour tour2;
    tour = tour2;
    CHECK(tour.num_cities() == CITIES_IN_TOUR);
}

TEST_CASE("A tour must contain all the cities in the CityList", "Assignment") {
    Tour tour;
    for (auto city : CityList::get_instance().shuffle()) {
        CHECK(tour.contains_city(city));
    }
}

TEST_CASE("Mutating a tour", "Assignment") {
    Tour tour;
    tour.mutate();
    CHECK(tour.num_cities() == CITIES_IN_TOUR);
}

TEST_CASE("Getter function return the properties of a tour", "Getters") {
    Tour tour;
    CHECK(tour.get_fitness() < 1);
    CHECK(tour.get_tour_distance() < (CITIES_IN_TOUR * City::MAX_MAP_BOUNDARY));
}