//
// Created by Herbert Ma on 2020-11-07.
//

#include <iostream>
#include <iomanip>
#include "../headers/City.hpp"
#include <cmath>

using std::to_string;
using std::swap;

City::City(int x, int y, string name): x(x), y(y), name(name) {
    check_coords();
}

City::City(const City &city) {
    x = city.x;
    y = city.y;
    name = city.name;
}

City & City::operator=(City city) {
    swap(*this, city);
    return *this;
}

void City::swap(City &lhs, City &rhs) {

    std::swap(lhs.x, rhs.x);
    std::swap(lhs.y, rhs.y);
    std::swap(lhs.name, rhs.name);
}

void City::check_coords() const {
    if (x < MIN_MAP_BOUNDARY || x > MAX_MAP_BOUNDARY || y < MIN_MAP_BOUNDARY || y > MAX_MAP_BOUNDARY) {
        throw std::invalid_argument("Coordinates must be within" + ::to_string(MIN_MAP_BOUNDARY) + " and " + ::to_string(MAX_MAP_BOUNDARY));
    }
}

ostream &operator<<(ostream &os, const City &c) {
    std::stringstream ss;
    ss.setf(std::ios_base::left);
    ss << std::setw(3) << std::setfill(' ') << c.name;
    ss << " x: " <<  std::setw(4) << std::setfill(' ') << c.x;
    ss << " y: " << c.y;
    os <<ss.str();
    return os;
}

double get_distance_between_cities(const City &c1, const City &c2) {
    double a = c1.x - c2.x;
    double b = c1.y - c2.y;
    double distance = sqrt(std::pow(a,2) + std::pow(b,2));
    return distance;
}

bool operator==(const City &left, const City &right) {
    return (left.x == right.x && left.y == right.y && left.name == right.name);
}

bool operator!=(const City &left, const City &right) {
    return !(left == right);
}