//
// Created by Teo on 12/01/2025.
//

#include "Graph.h"

#include <fstream>


Graph Graph::readGraphFromFile(const std::string &filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier");
    }

    int order;
    inputFile >> order;
    Graph graph(order);

    int node;
    while (inputFile >> node) {
        int neighbor;
        int cost;
        while (inputFile >> neighbor >> cost && neighbor != 0) {
            if (node < neighbor) {
                graph.addEdge(node - 1, neighbor - 1, cost);
            }
        }
    }

    inputFile.close();
    return graph;
}