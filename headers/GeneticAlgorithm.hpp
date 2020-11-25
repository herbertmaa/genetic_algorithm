//
// Created by Herbert Ma on 2020-11-08.
//

#pragma once

#include "Tour.hpp"
#include "Comparator.hpp"
#include "ToursManager.hpp"

#include <queue>
#include <functional>

class GeneticAlgorithm{

private:
    double base_fitness = 0; // Starting fitness for the algorithm, initialized when object is created
    ToursManager * manager; // A pointer to the manager in charge of managing tours
public:
    static constexpr int ITERATIONS = 5000; // The number of iterations to go through
    static constexpr double DESIRED_IMPROVEMENT = 0.35; // The desired improvement factor
    /**
     * Creates a random list of cities and tours managed by the ToursManager
     */
    GeneticAlgorithm();

    /* Destructor for deleting any dynmically allocated memory */
    ~GeneticAlgorithm();

    /**
     * Function to run the Genetic algorithm ITERATIONS time OR until an improvement factor has been reached
     */
    void run();

};