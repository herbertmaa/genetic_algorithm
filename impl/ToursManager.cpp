//
// Created by Yogesh Verma on 2020-11-22.
//

#include <random>
#include <algorithm>
#include <iostream>
#include "../headers/ToursManager.hpp"
#include "../headers/CityList.hpp"

using std::endl;
using std::cout;

ToursManager::ToursManager() {
    // Allocate memory by creating new tours and putting tours into a priority queue
    for (int i = 0; i < NUMBER_OF_TOURS; ++i) {
        Tour *base_tour = new Tour();
        base_tours.push(base_tour);
    }
}

double ToursManager::get_elite_distance() const {
    return base_tours.top()->get_tour_distance();
}

double ToursManager::get_elite_fitness() const {
    return base_tours.top()->get_fitness();
}

Tour *ToursManager::select_parents(const vector<Tour *> &tours) {
    // Create a queue for the parents
    queue parents;
    std::random_device rd;
    std::mt19937 eng{rd()};
    std::uniform_int_distribution<int> dist{0, NUMBER_OF_TOURS - 2};

    // Grab tours from random indices of the vector tours provided.
    for (int i = 0; i < PARENT_POOL_SIZE; ++i) {
        int rand = dist(eng);
        parents.push(tours.at(rand));
    }

    // Return a pointer to the best one out of this bunch
    return parents.top();
}

void ToursManager::crossover() {
    // A vector containing our new tour list
    vector<Tour *> temp;

    // Create a Tour pointer to our best tour so far
    Tour* elite = base_tours.top();
    base_tours.pop();

    // Unload our priority queue and convert it into a vector.
    while (!base_tours.empty()) {
        temp.push_back(base_tours.top());
        base_tours.pop();
    }

    for (int i = 0; i < NUMBER_OF_TOURS-1; ++i) {
        // Create a pair of parents
        std::pair<Tour *, Tour *> pair;

        pair.first = select_parents(temp);
        pair.second = select_parents(temp);

        // Cross them to make a new Tour
        Tour *crossed = new Tour{*pair.first, *pair.second};

        // Add the Tour to our base_tour
        base_tours.push(crossed);
    }

    // Re-add back the base_tour
    base_tours.push(elite);
    // Everything in temp is now previous generations of tours. We can safely delete those.
    for (auto it = temp.begin(); it != temp.end(); ++it) {
        delete (*it);
        *it = nullptr;
    }
}

ToursManager::~ToursManager() {
    // Deallocate memory from creating Tours
    while (!base_tours.empty()) {
        delete base_tours.top();
        base_tours.pop();
    }
}

void ToursManager::pick_and_mutate() {
    std::mt19937 e{std::random_device{}()};
    std::uniform_real_distribution<double> dist(0, 1);

    queue new_tours;

    // Remove the first element from the queue
    Tour *elite = base_tours.top();
    base_tours.pop();

    // While the queue is not empty continually pop from it
    while (!base_tours.empty()) {
        double rand = dist(e);
        Tour *current = base_tours.top();
        base_tours.pop();

        // Mutate the tour if it meets the criteria
        if (rand < TO_BE_MUTATED) {
            current->mutate();
        }
        // Push it into the new tour list
        new_tours.push(current);
    }
    // Put the elite back into the new tour list
    new_tours.push(elite);

    // Copy all elements of the tour list back into the original tour list.
    while (!new_tours.empty()) {
        base_tours.push(new_tours.top());
        new_tours.pop();
    }
}

void ToursManager::print_tours() const {
    //Create a copy of the priority queue, pop from this to preserve the queue in ToursManager
    queue temp = this->base_tours;
    while (!temp.empty()) {
        std::cout << *(temp.top()) << std::endl;
        temp.pop();
    }
}

