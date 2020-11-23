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
    static constexpr int NUMBER_OF_PARENTS = 2;
    static constexpr int POPULATION_SIZE = 32;
    void init();
    double base_distance = 0;
    queue base_tours;
    queue get_parent_subset(const vector<Tour *>& tours);

public:
    ToursManager();
    double get_elite_fitness() const;
    double get_elite_distance() const;
    void print_tours() const;
    void generate_merged_tours(queue& tours);
    void pick_and_mutate(double mutation_rate);
    inline queue& get_base_tours() { return base_tours; }

    ~ToursManager();
};
