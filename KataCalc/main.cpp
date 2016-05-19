#include <iostream>
#include <c++/bitset>

using namespace std;

unsigned long add(unsigned long long a,unsigned long long b){
    std::bitset<8> first(a);
    std::bitset<8> second(b);
    std::bitset<8> result;
    int temp = 0;

    for (int i = 0; i < 8;i++){
        if(first[i] && second[i]){
            result[i] = temp;
            temp = 1;
        }
        if(!first[i] && !second[i]){
            result[i] = temp;
            temp = 0;
        }
        if(first[i] xor second[i]){
            if(temp){
                result[i] = 0;
            } else {
                result[i] = 1;
                temp = 0;
            }
        }
    }
    return result.to_ulong();
}

long subtract(unsigned long long a,unsigned long long b){
    int sign = 1;
    if(b > a){
        unsigned long long temp = a;
        a = b;
        b = temp;
        sign = -1;
    }
    std::bitset<8> neg(a);
    std::bitset<8> result(add((~neg).to_ulong(),b));

    return (~result).to_ulong()*sign;
}

long long multiple(unsigned long long a,unsigned long long b){
    std::bitset<8> first(a);
    std::bitset<8> second(b);
    unsigned long long result = 0;
    for (int i = 0; i < 8;i++){
       if(second[i]==0) continue;
        result = add(result,(first <<= i).to_ulong());
    }
    return result;
}

long divide(unsigned long long a,unsigned long long b){
    std::bitset<8> first(a);
    std::bitset<8> second(b);
    std::bitset<8> oldSecond(b);
    std::bitset<8> result;
    second<<=2;
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

int main() {
    cout << add(2,3) << endl;
    cout << subtract(4,5) << endl;
    cout << multiple(2,5) << endl;
    cout << divide(8,2) << endl;
    return 0;
}