//
// Created by Herbert Ma on 2020-11-07.
//

#include <iostream>
#include <iomanip>
#include "../headers/City.hpp"
#include <cmath>

using std::to_string;

City::City(int x, int y, string name): x(x), y(y), name(name) {
    check_coords();
}

void City::check_coords() {
    if (x <= MIN_RANGE || x >= MAX_RANGE || y <= MIN_RANGE || y >= MAX_RANGE) {
        throw std::invalid_argument("Coordinates must be within" + ::to_string(MIN_RANGE) + " and " + ::to_string(MAX_RANGE));
    }
}

ostream &operator<<(ostream &os, const City &c) {
    std::stringstream ss;
    ss.setf(std::ios_base::left);
    ss << std::setw(3) << std::setfill(' ') << c.name;
    ss << " x: " <<  std::setw(4) << std::setfill(' ') << c.x;
    ss << " y: " << c.y << "\n";
    os <<ss.str();
    return os;
}

double get_distance_between_cities(const City &c1, const City &c2) {
    double a = c1.x - c2.x;
    double b = c1.y - c2.y;
    double distance = sqrt(std::pow(a,2) + std::pow(b,2));
    return distance;
}
