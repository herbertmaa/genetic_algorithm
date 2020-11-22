//
// Created by Herbert Ma on 2020-11-08.
//

#include <iostream>
#include <random>
#include "../headers/GeneticAlgorithm.hpp"

GeneticAlgorithm::GeneticAlgorithm() {
    manager.init();
    this->base_distance = manager.get_elite_distance(manager.get_base_tours());
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
    os << "Lowest distance so far: " << g.base_distance << std::endl;
    os << "Printing out algorithm results \n";
    queue tours = g.manager.get_base_tours();
    while(!tours.empty()){
        auto value = tours.top();
        os << value->get_total_distance() << "\n";
        tours.pop();
        os << *value;
    }
    return os;
}

GeneticAlgorithm::~GeneticAlgorithm() {

}

