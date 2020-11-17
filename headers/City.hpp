//
// Created by Herbert Ma on 2020-11-07.
//

#pragma once

#include <string>

using std::string;
using std::ostream;

class City{
private:
    int x; // longitude
    int y; // latitude
    string name;
public:
    static constexpr int max_range = 1000;
    static constexpr int min_range = 0;

    City(int x, int y, string name):x(x), y(y), name(name){}

    inline int get_x() { return x; }
    inline int get_y() { return y; }
    inline string get_name() { return name; }

    friend ostream&operator <<(ostream&os, const City& c);
    friend double get_distance_between_cities(const City&c1, const City&c2);

    ~City() = default;
};