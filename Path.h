//
// Created by Teo on 12/01/2025.
//

#ifndef PATH_H
#define PATH_H



class Path {
    int src;
    int dest;
    int weight;

public:
    Path(const int s, const int d, const int w): src(s), dest(d), weight(w) {};
};



#endif //PATH_H
