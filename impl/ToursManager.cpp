//
// Created by Yogesh Verma on 2020-11-22.
//

#include "../headers/ToursManager.hpp"

void ToursManager::init() {
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        Tour* base_tour= new Tour();
        base_tours.push(base_tour);
    }
}

int ToursManager::get_elite_distance(queue tours) {
    return tours.top()->get_total_distance();
}

ToursManager::~ToursManager() {
    while (!base_tours.empty()) {
        delete base_tours.top();
        base_tours.pop();
    }
}
