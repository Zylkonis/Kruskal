//
// Created by Teo on 12/01/2025.
//

#include "Graph.h"

void Graph::addEdge(int src, int dest, int weight) {
    paths.push_back({src, dest, weight});
}
