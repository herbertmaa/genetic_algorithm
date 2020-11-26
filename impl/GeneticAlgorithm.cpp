//
// Created by Herbert Ma on 2020-11-08.
//

#include <iostream>
#include <random>
#include "../headers/GeneticAlgorithm.hpp"
#include "../headers/CityList.hpp"

using namespace std;

GeneticAlgorithm::GeneticAlgorithm(): manager(new ToursManager) {
    this->base_distance = manager->get_elite_distance();
}

void GeneticAlgorithm::run() {
    cout << "**** Genetic Algorithm started ****" << endl;
    cout << endl;

    int iterations = 0;
    this->base_distance = manager->get_elite_distance();

    Tour* base_tour = manager->get_copy_elite();

    double new_distance;
    double best_distance = manager->get_elite_distance();
    double improvement_amount = 0;

    // Perform the GeneticAlgorithm if we have not met our desired fitness or have done enough iterations
    while(improvement_amount < DESIRED_IMPROVEMENT && iterations < GeneticAlgorithm::ITERATIONS){

        cout << "==Iteration number " << iterations << "==" << endl;

        // Generate a new generation of tours from our existing tours
        this->manager->crossover();

        // Pick and mutate the new generation of tours
        this->manager->pick_and_mutate();

        // Get the new best distance
        new_distance = this->manager->get_elite_distance();

        // Update the best distance
        if(this->manager->get_elite_distance() < best_distance){
            best_distance = new_distance;
        }

        // Update the improvement amount
        improvement_amount = (abs(base_distance - new_distance)/base_distance);

        cout << "Distance for this iteration " << this->manager->get_elite_distance() << endl;
        cout << "Best distance so far " << new_distance << endl;
        cout << "Improvement over base " << improvement_amount << endl;

        if(improvement_amount < DESIRED_IMPROVEMENT){
            cout << "Improvement not achieved" << endl;
        }else{
            cout << "Improvement achieved" << endl;
        }
        cout << endl;

        // Increment the iterations
        ++iterations;
    }

    cout << "**** Genetic Algorithm ended ****" << endl;
    cout << endl;

    Tour* best_tour = manager->get_copy_elite();
    generate_report(iterations, base_distance, best_distance, improvement_amount >= DESIRED_IMPROVEMENT, base_tour, best_tour);

    delete base_tour;
    delete best_tour;
}

GeneticAlgorithm::~GeneticAlgorithm() {
    delete manager;
}

void GeneticAlgorithm::generate_report(int iterations, double base_distance, double best_distance, bool achieved, Tour* base_route, Tour* best_route) {
    cout << "**** Genetic Algorithm Report ****" << endl;
    cout << "Number of iterations " << iterations << endl;
    cout << "Base distance:  " << base_distance << endl;
    cout << "Best distance:  " << best_distance << endl;
    print_achieved(achieved);
    cout << "Base tour " << endl;
    cout << *base_route << endl;
    cout << "\n";
    cout << "Best tour " << endl;
    cout << *best_route << endl;
}

void GeneticAlgorithm::print_achieved(bool achieved){
    if(!achieved){
        cout << "Improvement not achieved" << endl;
    }else{
        cout << "Improvement achieved" << endl;
    }

}

