#include <iostream>
#include "headers/GeneticAlgorithm.hpp"

#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    int result;

    try {
        // bootstrap Catch, running all TEST_CASE sequences.
        result = Catch::Session().run(argc, argv);
    } catch (const std::exception& ex) {
        auto pMessage = ex.what();
        if (pMessage) {
            std::cout << "An unhandled exception was thrown:\n" << pMessage;
        }
        std::cin.get(); // Immediate feedback.
        return -1;
    }
  
//    GeneticAlgorithm g{};
    return result;
}
