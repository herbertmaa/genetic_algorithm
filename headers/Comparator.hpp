//
// Created by Herbert Ma on 2020-11-09.
//

#pragma once

/* Class to help us compare pointers of a Tour */
struct Comparator{
    template<typename T>
    bool operator()(T* a, T* b) {
        return ((*a) < (*b));
    }
};