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
    static constexpr int NUMBER_OF_TOURS = 5;
    void init();
    double base_distance = 0;
    inline queue& get_base_tours() { return base_tours; }

public:
    queue base_tours;
    ToursManager();
    double get_elite_fitness() const;
    double get_elite_distance() const;
    void print_tours() const;
    void pick_and_mutate(double mutation_rate);
    queue get_parent_subset(const vector<Tour *>& tours);
    void generate_merged_tours(queue& tours);
    ~ToursManager();
    void crossandtoss();
};
