//
// Created by Yogesh Verma on 2020-11-22.
//

#pragma once

#include <queue>
#include <vector>
#include "Tour.hpp"
#include "Comparator.hpp"

using std::priority_queue;
using std::vector;

typedef priority_queue<Tour *, std::vector<Tour *>, Comparator> queue; // A minimum priority queue

class ToursManager {
private:
    static constexpr int PARENT_POOL_SIZE = 5; // The size of the subsets to generate
    static constexpr int NUMBER_OF_TOURS = 32; // The number of tours that this manager will generate and manage
    static constexpr double TO_BE_MUTATED = 0.25; // The chance that the tour will have its cities mutated
    double base_distance = 0; // The lowest distance of all tours managed by the Tour Manager
    queue base_tours; // A priority queue to track tours

    /**
    * Returns a pointer to the lowest distance tour from a subset of tours
    * @param tours - A vector of tours
    * @return - The lowest distance tour from the vector
    */
    Tour *select_parents(const vector<Tour *> &tours);

public:
    /**
     * Creates a TourManager managing NUMBER_OF_TOURS
     */
    ToursManager();

    /**
     * Destructor for a TourManager, responsible for deallocating memory in the queue
     */
    ~ToursManager();

    /**
     * Gets the best fitness value from the top of the queue
     * @return - The largest fitness value from all the tours
     */
    double get_elite_fitness() const;

    /**
     * Gets the lowest distance value from the top of the queue
     * @return - The lowest distance value from all the tours
     */
    double get_elite_distance() const;

    /**
     * Helper method for printing out all the tours and their respective cities
     */
    void print_tours() const;

    /**
     * Helper method that creates a new generation of tours from the existing tours in Tour Manager
     */
    void crossover();

    /**
     * Helper method that picks and mutates a tour based on TO_BE_MUTATED percentage
     */
    void pick_and_mutate();

    /**
     * Generates a copy of the current elite using dynamic memory
     * The caller of this method is responsible for deallocating memory for the tour generated from this method.
     * @return - A new reference to the current elite tour.
     */
    Tour* get_copy_elite();

};
