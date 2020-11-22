//
// Created by Herbert Ma on 2020-11-08.
//

#include <iostream>
#include <random>
#include "../headers/GeneticAlgorithm.hpp"

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

Tour* GeneticAlgorithm::crossover(const Tour &t1, const Tour &t2) {

    Tour* new_tour = new Tour{}; //make a copy of T1
    std::random_device rd;

    std::uniform_int_distribution<int> begin(0, t1.num_cities()-1);
    int end_offset = begin(rd); // the ending index of T1 to grab cities from


//    if(begin_offset == end_offset){
//        new_tour->insert_city_front(t1.)
//    }else{
//
//    }


    return new_tour;
}




