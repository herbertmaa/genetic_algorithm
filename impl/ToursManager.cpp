//
// Created by Yogesh Verma on 2020-11-22.
//

#include <random>
#include <algorithm>
#include "../headers/ToursManager.hpp"
#include "../headers/CityList.hpp"

void ToursManager::init() {
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        Tour* base_tour= new Tour();
        base_tours.push(base_tour);
    }
}

int ToursManager::get_elite_distance(queue tours) {
    return tours.top()->get_total_distance();
}

queue ToursManager::get_parent_subset(const vector<Tour *>& tours) {
    queue parents;
    std::random_device rd;
    std::mt19937 eng{rd()};
    std::uniform_int_distribution<int> dist{0, CityList::CITIES_IN_TOUR - 1};
    for (int i = 0; i < PARENT_POOL_SIZE; ++i) {
        parents.push(tours.at(i));
    }
    return parents;
}

void ToursManager::generate_merged_tours(queue& tours) {
    vector<Tour *> temp;
    Tour * fittest = tours.top();

    tours.pop();

    while (!tours.empty()) {
        temp.push_back(tours.top());
        tours.pop();
    }

    for (int i = 0; i < POPULATION_SIZE - 1; ++i) {
        Tour * parents[NUMBER_OF_PARENTS];
        for (int i = 0; i < NUMBER_OF_PARENTS; ++i) {
            queue parent_queue = get_parent_subset(temp);
            parents[i] = parent_queue.top();
        }
        Tour * crossed = new Tour {parents};
        tours.push(crossed);
    }
    tours.push(fittest);
}


ToursManager::~ToursManager() {
    while (!base_tours.empty()) {
        delete base_tours.top();
        base_tours.pop();
    }
}
