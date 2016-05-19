//
// Created by mkuba on 20.05.2016.
//

#ifndef KATACALC_BINARYCALC_H
#define KATACALC_BINARYCALC_H

#include <c++/bitset>

class BinaryCalc{
public:
    BinaryCalc();
    unsigned long long add(unsigned long long one,unsigned long long two);
    long subtract(unsigned long long one,unsigned long long two);
    long long multiple(unsigned long long one,unsigned long long two);
    long long divide(unsigned long long one,unsigned long long two);
};
#endif //KATACALC_BINARYCALC_H
