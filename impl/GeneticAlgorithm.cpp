//
// Created by Herbert Ma on 2020-11-08.
//

#include <iostream>
#include <random>
#include "../headers/GeneticAlgorithm.hpp"

using namespace std;

GeneticAlgorithm::GeneticAlgorithm() {
    manager = new ToursManager();
    this->base_fitness = manager->get_elite_fitness();
    manager->print_tours();
    run();
}

/**
 * Overloaded output operator, note this overloaded method makes a copy of the original GeneticAlgorithm object
 * As std::priority_queue does not allow iteration we make a copy and then pop() from the tour to get the output
 * @param os - The stream to output to
 * @param g - The GeneticAlgorithm object
 * @return - A stream containing a list of the tours in the algorithm
 */
ostream &operator<<(ostream &os, GeneticAlgorithm g) {
    //does not modify the original heap as this makes a copy
//    os << "Lowest distance so far: " << g.base_distance << std::endl;
//    os << "Printing out algorithm results \n";
//    queue tours = g.manager.get_base_tours();

//
//    g.manager.generate_merged_tours(g.manager.get_base_tours());
//    value = g.manager.get_base_tours().top();
//    os << value->get_total_distance() << "\n";
//    tours.pop();
//    os << *value;
////    }
    return os;
}

GeneticAlgorithm::~GeneticAlgorithm() {



}

void GeneticAlgorithm::run() {

    int iterations = 0;
    double desired_fitness = 1000.00; //TODO hardcoded for now

//    this->manager->generate_merged_tours(this->manager->base_tours);
    manager->crossandtoss();
//    manager->print_tours();
//    while(base_fitness < desired_fitness || iterations < GeneticAlgorithm::ITERATIONS){
//
//        this->manager->crossandtoss();
//        this->manager->pick_and_mutate(Tour::MUTATION_RATE);
//
//        ++iterations;
//    }
}
