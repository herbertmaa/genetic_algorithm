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
    string name; // the name of the city

    /*
     * Helper function to check coordinates being passed into a city.
     * If coordinates do not fall within the MIN and MAX MAP boundaries this function will throw an exception
     */
    void check_coords() const;

    /**
     * Helper function to swap two cities, swaps the two cities x and y coordinates and name
     * @param lhs - The left city to swap
     * @param rhs - The right city to swap
     */
    void swap(City& lhs, City& rhs);
public:
    static constexpr int MAX_MAP_BOUNDARY = 1000; // max coordinate of a city
    static constexpr int MIN_MAP_BOUNDARY = 0; // min coordinate of a city

    /**
     * Creates a city with the provided x, y, and name
     * @param x - The x coordinate of the city
     * @param y - The y coordinate of the city
     * @param name - The name of the city
     */
    City(int x, int y, string name);

    /**
     * Copy constructor that creates a city from another
     * @param city - The city to copy
     */
    City(const City& city);

    /* Default destructor */
    ~City() = default;

    /**
     * City assignment operator
     * @param city - The right hand side of the assignment
     * @return - A reference to the modified City
     */
    City& operator=(City city);

    /* Getter method for the x coordinate */
    inline int get_x() const { return x; }

    /* Getter method for the y coordinate */
    inline int get_y() const { return y; }

    /* Getter method for the name */
    inline string get_name() const { return name; }

    /**
     * Helper function to print the City
     * @param os - The output stream to write to
     * @param c - The reference to the City being printed
     * @return - The modified output stream
     */
    friend ostream&operator <<(ostream&os, const City& c);

    /**
     * Helper function to get the distance between two cities
     * @param c1 - The first city
     * @param c2 - The second city
     * @return - The distance between the two cities using distance between two points
     */
    friend double get_distance_between_cities(const City&c1, const City&c2);

    /**
     * Overloaded == operator to compare two cities
     * @param left - The left city to compare to
     * @param right - The right city to compare to
     * @return - Whether the two cities are equal
     */
    friend bool operator ==(const City& left, const City& right);

    /**
     * Overloaded != operator to compare two cities
     * @param left - The left city to compare to
     * @param right - The right city to compare to
     * @return - Whether the two cities are not equal
     */
    friend bool operator !=(const City& left, const City& right);

};