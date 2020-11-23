//
// Created by Herbert Ma on 2020-11-08.
//

#pragma once

#include "Tour.hpp"
#include "Comparator.hpp"
#include <queue>
#include <functional>

class GeneticAlgorithm{

public:
    GeneticAlgorithm();

    void pickAndMutate(double mutation_rate);

private:
    double base_distance = 0;
    std::priority_queue<Tour*, std::vector<Tour*>, Comparator> tours;
    friend ostream&operator <<(ostream&os, GeneticAlgorithm g);
    Tour* crossover(const Tour& t1, const Tour& t2);
};