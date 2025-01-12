//
// Created by Teo on 12/01/2025.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <Path.h>
#include <List.h>


class Graph {
    int order;
    List<Path> paths;

public:
    Graph(int o): order(o) {};

    void addEdge(int src, int dest, int weight);

    Graph readGraphFromFile(const std::string &filename);
};



#endif //GRAPH_H
