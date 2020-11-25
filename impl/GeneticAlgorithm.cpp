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

/**
 * Overloaded output operator, note this overloaded method makes a copy of the original GeneticAlgorithm object
 * As std::priority_queue does not allow iteration we make a copy and then pop() from the tour to get the output
 * @param os - The stream to output to
 * @param g - The GeneticAlgorithm object
 * @return - A stream containing a list of the tours in the algorithm
 */
ostream &operator<<(ostream &os, const GeneticAlgorithm& g) {
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

void GeneticAlgorithm::run() {
    int iterations = 0;
    double desired_improvement = 0.15;

    base_fitness = manager->get_elite_fitness();
    double new_fitness = base_fitness;

    while((abs(base_fitness - new_fitness)/base_fitness) < desired_improvement || iterations < GeneticAlgorithm::ITERATIONS){

//        while(iterations < 5){
        this->manager->cross_tours();
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
