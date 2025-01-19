//
// Created by Teo on 18/01/2025.
//

#ifndef PAIR_H
#define PAIR_H


template<typename T, typename U>
class Pair {
private:
    T first;
    U second;

public:
    Pair(T e1, U e2): first(e1), second(e2) {}

    T getFirst() {
        return first;
    }

    U getSecond() {
        return second;
    }
};



#endif //PAIR_H
