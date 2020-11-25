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
    const double desired_improvement = 0.35;

    base_fitness = manager->get_elite_fitness();
    double new_fitness = base_fitness;

    while((abs(base_fitness - new_fitness)/base_fitness) < desired_improvement && iterations < GeneticAlgorithm::ITERATIONS){
        this->manager->crossover();
        this->manager->pick_and_mutate(Tour::MUTATION_RATE);
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
