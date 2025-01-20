//
// Created by Teo on 12/01/2025.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <List.h>
#include <Matrix.h>

#include "Map.h"
#include "Pair.h"

class Graph {
private:
    int order;
    Map<int, List<Pair<int, int>>> edgesL;    //  Map<Sommet_source, List<Sommet_destination, poids>>
    Matrix<int> edgesM;


public:
    Graph(const int o): order(o), edgesM(Matrix<int>(o, o, 0)) {
        for (int i = 1; i <= order; i++) {
            edgesL.add(i, List<Pair<int, int>>());
        }
    };

    // Lis un fichier texte pour former le graph sous forme de liste d'adjacence
    static Graph readGraphFromFile(const std::string &filename);

    int getOrder() const {
        return order;
    }

    Map<int, List<Pair<int, int>>> getEdgesL() const {
        return edgesL;
    }

    Matrix<int> getEdgesM() const {
        return edgesM;
    }

    void addEdge(int src, int dest, int weight) {
        edgesL.get(src).push_back({dest, weight});
        edgesL.get(dest).push_back({src, weight});

        edgesM(src - 1, dest - 1) = weight;
        edgesM(dest - 1, src - 1) = weight;
    }
};



#endif //GRAPH_H