//
// Created by Hadar on 18-Jan-20.
//

#ifndef DSA_PROJECT_2_PAIR_H
#define DSA_PROJECT_2_PAIR_H

#include <cstddef>

template <typename T, typename U> class Pair {
public:
    T * first;
    U * second;

    Pair(T *first, U *second) : first(first), second(second) {}
};

#endif //DSA_PROJECT_2_PAIR_H
