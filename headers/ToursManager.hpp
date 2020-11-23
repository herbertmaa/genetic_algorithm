//
// Created by Yogesh Verma on 2020-11-22.
//

#pragma once

#include <queue>
#include "Tour.hpp"

using std::priority_queue;

typedef priority_queue<Tour*, std::vector<Tour*>, std::greater<Tour*>> queue;

class ToursManager {
private:
    static constexpr int PARENT_POOL_SIZE = 5;
    static constexpr int NUMBER_OF_PARENTS = 20;
    static constexpr int POPULATION_SIZE = 32;

    double base_distance = 0;

    queue base_tours;

    queue get_parent_subset();
    queue generate_merged_tours();
    Tour * cross(Tour * parents[NUMBER_OF_PARENTS]);

public:
    ToursManager() = default;
    void init();

    int get_elite_distance(queue tours);

    inline queue get_base_tours() {
        return base_tours;
    }

    ~ToursManager();
};
