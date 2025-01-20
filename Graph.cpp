//
// Created by Teo on 12/01/2025.
//

#include "Graph.h"

#include <fstream>


Graph Graph::readGraphFromFile(const std::string &filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        throw std::runtime_error("File not found: " + filename);
    }

    int order;
    inputFile >> order;  // Lire l'ordre du graphe
    Graph graph(order);

    int node;
    // On lit chaque ligne du fichier
    while (inputFile >> node) {
        int neighbor, cost;

        // On traite les voisins et coûts pour ce sommet
        while (inputFile >> neighbor) {
            if (neighbor == 0) break;  // Fin des voisins pour ce sommet

            inputFile  >> cost;
            graph.addEdge(node, neighbor, cost);  // Ajouter l'arête
        }
    }

    inputFile.close();
    return graph;
}