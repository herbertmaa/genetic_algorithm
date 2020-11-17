//
// Created by Herbert Ma on 2020-11-08.
//

#pragma once

#include "Tour.hpp"
#include <queue>
#include <functional>

class GeneticAlgorithm{

public:
    GeneticAlgorithm();

private:
    double base_distance = 0;
    std::priority_queue<Tour*, std::vector<Tour*>, std::greater<Tour*>> tours;
    friend ostream&operator <<(ostream&os, GeneticAlgorithm g);

};