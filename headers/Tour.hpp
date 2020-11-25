//
// Created by Herbert Ma on 2020-11-07.
//

#pragma once

#include "City.hpp"
#include <vector>

using std::ostream;

class Tour {
private:
    std::vector<City *> cities; // A vector of pointers to cities, the order of these pointers represent the tour
    double fitness = 0; // The fitness of this tour
    double total_distance = 0; // The total_distance from the first city to the last city

    /**
     * Determine the fitness of the tours and assign the fitness instance variable to the calculated fitness
     */
    void determine_fitness();

    /**
     * Helper function to swap two tours
     * @param lhs - The left tour to swap
     * @param rhs - The right tour to swap
     */
    void swap(Tour& lhs, Tour& rhs);

public:
    constexpr static double MUTATION_RATE = 0.5; // Chance that a city will get mutated within this Tour
    constexpr static int RANDOM_SEED = 37; // A random number used within our fitness calculation

    /* Default constructor for creating our Tour of randomly organized Cities*/
    Tour();

    /**
     * A copy constructor for creating tours
     * @param rhs - The tour to copy from
     */
    Tour(const Tour& rhs);

    /**
     * A tour constructor that creates a tour from two parents
     * @param t1 - One of the parent tours to cross from
     * @param t2 - One of the parent tours to cross from
     */
    Tour(const Tour& t1, const Tour& t2);

    /* Destructor for tour, clears the vector */
    ~Tour() { cities.clear();};
    /**
     * Assigns another tours contents to this Tour
     * @param assignment - The right hand side of the assignment operator
     * @return - A reference to the modified Tour
     */
    Tour& operator=(Tour assignment);

    /**
     * Checks if a city is in the cities list of this tour
     * @param city - The city to check
     * @return - True if the city is in the tour list, otherwise false
     */
    bool contains_city(City* city) const;

    /**
     * Mutates the tour list, cities will be randomly swapped with a neighbour
     */
    void mutate();

    /* Getter method for fitness */
    double get_fitness() const;

    /* Getter method for the tour distance */
    inline double get_tour_distance() const {return this->total_distance;};

    /**
     * Overloaded output operator
     * @param os - The output stream to output to
     * @param t - The tour to print out
     * @return - The modified output stream
     */
    friend ostream&operator <<(ostream&os, const Tour& t);

    /**
     * Overloaded less than operator to determine if one tour is less than the other
     * @param t2 - The right hand side of the < operation
     * @return - True if T2 is greater than T1 otherwise false
     */
    bool operator < (const Tour& t2) const;

};

