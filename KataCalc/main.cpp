#include <iostream>
#include "BinaryCalc.h"


int main() {

    BinaryCalc* binaryCalc = new BinaryCalc();
    std::cout << binaryCalc->add(2,3) << std::endl;
    std::cout << binaryCalc->subtract(4,5) << std::endl;
    std::cout << binaryCalc->multiple(2,5) << std::endl;
    std::cout << binaryCalc->divide(8,2) << std::endl;
    return 0;
}