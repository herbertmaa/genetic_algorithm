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
    string name;;
public:
    static constexpr int max_range = 1000;
    static constexpr int min_range = 0;
    City(int x, int y, string name):x(x), y(y), name(name){}
    ~City() = default;
    friend ostream&operator <<(ostream&os, const City& c);

};