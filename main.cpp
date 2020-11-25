#include <iostream>
#include "headers/GeneticAlgorithm.hpp"
#include "headers/CityList.hpp"
#include <algorithm>    // std::find
#include <cmath>

#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

using namespace std;

void test_tour_manager();
void test_shuffle();
void test_get_distance_between_cities();
void test_equality_cities();
void test_assignment_cities();
void test_city_copy();
void test_tour_mutate();

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
//    test_shuffle();
//    test_get_distance_between_cities();
//    test_equality_cities();
//    test_assignment_cities();
//    test_city_copy();
    return result;
}

void test_tour_mutate() {
    Tour tour {};
    cout << tour << endl;
    tour.mutation();
    cout << tour << endl;
}

void test_tour_manager(){
    ToursManager manager;
    manager.print_tours();
}

void test_shuffle(){
    CityList& c = CityList::get_instance();

    vector<City* > result = c.shuffle();
    int count1 = 0;

    for(auto it = result.begin(); it < result.end(); ++it){
        cout << **it << endl;
        ++count1;
    }
    vector<City* > result2 = c.shuffle();
    int count2 = 0;

    bool failed = false;
    for(auto it = result2.begin(); it < result2.end(); ++it){
        ++count2;
        if(std::find(result.begin(), result.end(), *it) == result.end()){
            failed = true;
            break;
        }
    }

    if(count1 != count2){
        cout << "this test failed, the two vectors are different sizes" << endl;
    }

    if(failed){
        cout << "this test failed, there is a city that exists in one and not another" << endl;
    }
}

void test_get_distance_between_cities(){
    City c{49,123, "Vancouver"};
    City c2{19, 73, "mumbai"};

    double func_answer = get_distance_between_cities(c, c2);
    double answer = sqrt(pow((49-19), 2) + pow((123-73), 2));

    if(func_answer != answer){
        cout << "FAILED" << endl;
    }else{
        cout << "DID NOT FAIL" << endl;
    }

}

void test_equality_cities(){
    City c{49, 123, "Vancouver"};
    City c2{49, 123, "Vancouver"};
    if(c != c2){
        cout << "FAILED" << endl;
    }
}


void test_assignment_cities(){
    City c{49, 123, "Vancouver"};
    City c2{19, 73, "mumbai"};
    c2 = c;
    cout << "c2 was originally mumbai and is now Vancouver" << endl;
    cout << c2 << endl;
}

void test_city_copy(){
    City c{49, 123, "Vancouver"};
    City c2{c};

    cout << "c2 is now a hard copy of c1" << endl;
    cout << c2 << endl;
}