#include <iostream>
#include "City.hpp"
#include "Tour.hpp";
int constexpr CITIES_IN_TOUR = 32;
int constexpr POPULATION_SIZE = 32;

using namespace std;

int main() {
    Tour t(30);
    cout << t;

    cout << "HEY" << endl;
    t.shuffle_cities();
    cout << t;
    return 0;
}
