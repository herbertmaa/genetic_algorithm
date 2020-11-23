#include <iostream>
#include "headers/GeneticAlgorithm.hpp"
using namespace std;

int main() {
    GeneticAlgorithm g{};


    for(int i = 0; i < 10; i++){
        cout << "Iteration " << i << endl;
        g.pickAndMutate(0.2);
        cout << g;
    }
    cout << g;
}
