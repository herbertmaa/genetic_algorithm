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
    void check_coords();
    void swap(City& lhs, City& rhs);
public:
    static constexpr int MAX_RANGE = 1000;
    static constexpr int MIN_RANGE = 0;

    City(int x, int y, string name);
    City(const City& city);
    City& operator=(City city);

    inline int get_x() { return x; }
    inline int get_y() { return y; }
    inline string get_name() { return name; }

    friend ostream&operator <<(ostream&os, const City& c);
    friend double get_distance_between_cities(const City&c1, const City&c2);
    friend bool operator ==(const City& left, const City& right);
    friend bool operator !=(const City& left, const City& right);
    ~City() = default;
};