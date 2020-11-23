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
    double base_distance = 0;
    ToursManager manager; // probably should be a pointer?
public:
    GeneticAlgorithm();
    ~GeneticAlgorithm();
    friend ostream&operator <<(ostream&os, GeneticAlgorithm g);
};