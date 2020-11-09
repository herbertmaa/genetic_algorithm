//
// Created by Herbert Ma on 2020-11-08.
//

#pragma once

#include "Tour.hpp";

class GeneticAlgorithm{

public:
    GeneticAlgorithm();

private:
    double base_distance = 0;
    std::vector<Tour*> tours;
};