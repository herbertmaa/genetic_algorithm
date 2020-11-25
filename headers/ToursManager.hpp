//
// Created by Yogesh Verma on 2020-11-22.
//

#pragma once

#include <queue>
#include <vector>
#include "Tour.hpp"
#include "Comparator.hpp"

using std::priority_queue;
using std::vector;

typedef priority_queue<Tour*, std::vector<Tour*>, Comparator> queue;

class ToursManager {
private:
    static constexpr int PARENT_POOL_SIZE = 5;
    static constexpr int NUMBER_OF_TOURS = 30;

    double base_distance = 0;
    queue base_tours;

public:
    ToursManager();
    ~ToursManager();

    inline queue& get_base_tours() { return base_tours; }
    double get_elite_fitness() const;
    double get_elite_distance() const;
    void print_tours() const;

    Tour * select_parents(const vector<Tour *>& tours);

    void crossover();
    void pick_and_mutate(double mutation_rate);
};
