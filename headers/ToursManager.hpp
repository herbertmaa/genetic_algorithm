//
// Created by Yogesh Verma on 2020-11-22.
//

#pragma once

#include <queue>
#include <vector>
#include "Tour.hpp"

using std::priority_queue;
using std::vector;

typedef priority_queue<Tour*, std::vector<Tour*>, std::greater<Tour*>> queue;

class ToursManager {
private:
    static constexpr int PARENT_POOL_SIZE = 5;
    static constexpr int NUMBER_OF_PARENTS = 2;
    static constexpr int POPULATION_SIZE = 32;

    double base_distance = 0;

    queue base_tours;

    queue get_parent_subset(const vector<Tour *>& tours);

public:
    ToursManager() = default;
    void init();

    int get_elite_distance(queue tours);
    void generate_merged_tours(queue& tours);
    void pickAndMutate(double mutation_rate);

    inline queue& get_base_tours() {
        return base_tours;
    }

    ~ToursManager();
};
