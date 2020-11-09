//
// Created by Herbert Ma on 2020-11-07.
//

#include <iostream>
#include <iomanip>
#include "City.hpp"
#include <cmath>

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
    double a = std::abs(c1.x - c2.x);
    double b = std::abs(c1.y - c2.y);
    double distance = sqrt(std::pow(a,2) + std::pow(b,2));
    return distance;
}
