//
// Created by Herbert Ma on 2020-11-09.
//

#pragma once

struct Comparator{
    template<typename T>
    bool operator()(T* a, T* b) {
        return ((*a) < (*b));
    }
};