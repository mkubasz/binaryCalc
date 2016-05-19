//
// Created by mkuba on 20.05.2016.
//

#include "BinaryCalc.h"

BinaryCalc::BinaryCalc(){

}

unsigned long long BinaryCalc::add(unsigned long long one, unsigned long long two){
    int moveBit = 0;
    std::bitset<8> first(one);
    std::bitset<8> second(two);
    std::bitset<8> result;

    for (int i = 0; i < 8;i++){
        if(first[i] && second[i]){
            result[i] = moveBit;
            moveBit = 1;
        }
        if(!first[i] && !second[i]){
            result[i] = moveBit;
            moveBit = 0;
        }
        if(first[i] xor second[i]){
            if(moveBit){
                result[i] = 0;
            } else {
                result[i] = 1;
                moveBit = 0;
            }
        }
    }
    return result.to_ulong();
}

long BinaryCalc::subtract(unsigned long long one, unsigned long long two){
    int sign = 1;
    if(two > one){
        unsigned long long temp = one;
        one = two;
        two = temp;
        sign = -1;
    }
    std::bitset<8> neg(one);
    std::bitset<8> result(add((~neg).to_ulong(),two));

    return (~result).to_ulong()*sign;
}

long long BinaryCalc::multiple(unsigned long long one, unsigned long long two){
    unsigned long long result = 0;
    std::bitset<8> first(one);
    std::bitset<8> second(two);

    for (int i = 0; i < 8;i++){
        if(second[i]==0) continue;
        result = add(result,(first <<= i).to_ulong());
    }
    return result;
}


long long BinaryCalc::divide(unsigned long long one, unsigned long long two){

    const std::bitset<8> oldSecond(two);
    std::bitset<8> counter(one);
    std::bitset<8> first(one);
    std::bitset<8> second(two);
    std::bitset<8> result;

    int counter_a = 0,counter_b = 0;
    while(counter.to_ulong()){
        counter >>=1;
        counter_a++;
    }
    counter = second;
    while(counter.to_ulong()){
        counter >>=1;
        counter_b++;
    }
    second<<=counter_a-counter_b;

    do
    {
        if(first.to_ulong() >= second.to_ulong()){
            std::bitset<8> temp((unsigned long long)subtract(first.to_ulong(),second.to_ulong()));
            first = temp;
            result[0] = 1;
        } else {
            result[0] = 0;
        }
        second >>=1;
        if(second.to_ulong() >= oldSecond.to_ulong()) {
            result.operator<<=(1);
        }

    }while(second.to_ulong() >= oldSecond.to_ulong());

    return result.to_ulong();
}