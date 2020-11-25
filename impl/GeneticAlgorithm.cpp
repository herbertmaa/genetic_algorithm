//
// Created by Herbert Ma on 2020-11-08.
//

#include <iostream>
#include <random>
#include "../headers/GeneticAlgorithm.hpp"
#include "../headers/CityList.hpp"

using namespace std;

GeneticAlgorithm::GeneticAlgorithm(): manager(new ToursManager) {
    this->base_fitness = manager->get_elite_fitness();
    run();
}

void GeneticAlgorithm::run() {
    int iterations = 0;

    base_fitness = manager->get_elite_fitness();
    double new_fitness = base_fitness;

    // Perform the GeneticAlgorithm if we have not met our desired fitness or have done enough iterations
    while((abs(base_fitness - new_fitness)/base_fitness) < DESIRED_IMPROVEMENT && iterations < GeneticAlgorithm::ITERATIONS){

        // Generate a new generation of tours from our existing tours
        this->manager->crossover();

        // Pick and mutate the new generation of tours
        this->manager->pick_and_mutate();

        // Get the new best fitness
        new_fitness = this->manager->get_elite_fitness();
        ++iterations;
        cout << this->manager->get_elite_fitness() << endl;
        cout << this->manager->get_elite_distance() << endl;
    }
    cout << "Number of iterations: " << iterations << endl;
}

GeneticAlgorithm::~GeneticAlgorithm() {
    delete manager;
}
