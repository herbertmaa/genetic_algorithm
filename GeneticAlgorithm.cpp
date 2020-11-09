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
    tours.push_back(base_tour);
    for(int i = 0; i < POPULATION_SIZE-1; i++){
        new_tour = new Tour(*base_tour);
        new_tour->shuffle_cities();
        tours.push_back(new_tour);
        std::cout << "\n";
        std::cout << *new_tour;
        double cur_fitness = new_tour->get_fitness();
        new_tour->mutation();
        std::cout << *new_tour;
        if(cur_fitness < lowest_fitness){
            lowest_fitness = cur_fitness;
        }
    }
    this->base_distance = lowest_fitness;
}

ostream &operator<<(ostream &os, const GeneticAlgorithm &g) {
    os << "Lowest fitness so far: " << g.base_distance << std::endl;
    os << "Printing out algorithm results \n";
    int i = 0;
    for(auto it = g.tours.begin(); it != g.tours.end(); ++it){
        os << "Tour: " << i << std::endl;
        os << **it;
        ++i;
    }
    return os;
}


