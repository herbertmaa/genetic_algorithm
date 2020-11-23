//
// Created by Yogesh Verma on 2020-11-22.
//

#include <random>
#include <algorithm>
#include <iostream>
#include "../headers/ToursManager.hpp"
#include "../headers/CityList.hpp"

void ToursManager::init() {
    for (int i = 0; i < NUMBER_OF_TOURS; ++i) {
        Tour* base_tour= new Tour();
        base_tours.push(base_tour);
    }
}

double ToursManager::get_elite_distance() const {
    return base_tours.top()->get_total_distance();
}

double ToursManager::get_elite_fitness() const {
    return base_tours.top()->get_fitness();
}

Tour * ToursManager::get_parent(const vector<Tour *>& tours) {
    queue parents;
    std::random_device rd;
    std::mt19937 eng{rd()};
    std::uniform_int_distribution<int> dist{0, NUMBER_OF_TOURS - 2};
    for (int i = 0; i < PARENT_POOL_SIZE; ++i) {
        int rand = dist(eng);
        parents.push(tours.at(rand)); //potential for picking yourself, but okay for now?
    }
    return parents.top();
}

void ToursManager::cross_tours() {
    vector<Tour *> temp;

    Tour * fittest = base_tours.top();

    base_tours.pop();

    while (!base_tours.empty()) {
        temp.push_back(base_tours.top());
        base_tours.pop();
    }

    for (int i = 0; i < NUMBER_OF_TOURS - 1; ++i) {
        Tour* parents[NUMBER_OF_PARENTS];
        for (int i = 0; i < NUMBER_OF_PARENTS; ++i) {
            parents[i] = get_parent(temp);
        }

        Tour * crossed = new Tour {*parents[0], *parents[1]};
        base_tours.push(crossed);
    }
    base_tours.push(fittest);

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
    while (!new_tours.empty()) {
        base_tours.push(new_tours.top());
        new_tours.pop();
    }
}

ToursManager::ToursManager() {
    init();
}

void ToursManager::print_tours() const{
    queue temp = this->base_tours;
    while(!temp.empty()){
        std::cout << *(temp.top()) << std::endl;
        temp.pop();
    }
}

