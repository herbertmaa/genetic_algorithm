//
// Created by Herbert Ma on 2020-11-08.
//

#include <iostream>
#include "GeneticAlgorithm.hpp"

int constexpr POPULATION_SIZE = 5;

GeneticAlgorithm::GeneticAlgorithm() {
    Tour* base_tour= new Tour(Tour::CITIES_IN_TOURS);
    Tour* new_tour = nullptr;
    double lowest_fitness = base_tour->get_fitness();
    tours.push(base_tour);
    for(int i = 0; i < POPULATION_SIZE-1; i++){
        new_tour = new Tour(*base_tour);
        new_tour->shuffle_cities();
        tours.push(new_tour);
    }
    this->base_distance = tours.top()->get_fitness();
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
    os << "Lowest fitness so far: " << g.base_distance << std::endl;
    os << "Printing out algorithm results \n";
    while(!g.tours.empty()){
        auto value = g.tours.top();
        os << value->get_fitness() << "\n";
        g.tours.pop();
        os << *value;
    }
    return os;
}


