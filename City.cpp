//
// Created by Herbert Ma on 2020-11-07.
//

#include <iostream>
#include <iomanip>
#include "City.hpp"

ostream &operator<<(ostream &os, const City &c) {
    std::stringstream ss;
    ss.setf(std::ios_base::left);
    ss << std::setw(3) << std::setfill(' ') << c.name;
    ss << " x: " <<  std::setw(4) << std::setfill(' ') << c.x;
    ss << " y: " << c.y << "\n";
    std::cout <<ss.str();
}
