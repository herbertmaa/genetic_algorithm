//
// Created by Herbert Ma on 2020-11-08.
//

#pragma once

#include "Tour.hpp"
#include "Comparator.hpp"
#include "ToursManager.hpp"

#include <queue>
#include <functional>

class GeneticAlgorithm{

private:
    double base_fitness = 0;
    ToursManager* manager;
public:
    static constexpr int ITERATIONS = 1000;
    GeneticAlgorithm();
    void run();
    ~GeneticAlgorithm();
    friend ostream&operator <<(ostream&os, GeneticAlgorithm g);
};