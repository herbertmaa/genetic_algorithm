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
    std::uniform_int_distribution<int> dist{0, POPULATION_SIZE - 2};
    for (int i = 0; i < PARENT_POOL_SIZE; ++i) {
        int rand = dist(eng);
        parents.push(tours.at(rand));
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

    for (auto it = temp.begin(); it != temp.end() ; ++it) {
        delete (*it);
        *it = nullptr;
    }
}


ToursManager::~ToursManager() {
    while (!base_tours.empty()) {
        delete base_tours.top();
        base_tours.pop();
    }
}

void ToursManager::pick_and_mutate(double mutation_rate) {
    //keep the implementation of mutate in tours otherwise you need a getter to the list of cities
    std::mt19937 e{std::random_device{}()};
    std::uniform_real_distribution<double> dist(0, 1);

    queue new_tours;
    Tour* elite = base_tours.top();
    while(!base_tours.empty()){
        double rand = dist(e);
        Tour* current = base_tours.top();
        base_tours.pop();
        if(rand > Tour::MUTATION_RATE){
            current->mutation();
        }
        new_tours.push(current);
    }
    new_tours.push(elite);
    base_tours = new_tours;
}

