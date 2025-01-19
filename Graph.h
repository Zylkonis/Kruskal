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

    int find(int u);
    void unionSets(int u, int v, List<int>& parent, List<int>& rank);
    bool isIn(int u) const;

public:
    Graph(const int o): order(o), edgesM(Matrix<int>(o, o, 0)) {};

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
        if (edgesL.containsKey(src)) {
            edgesL.get(src).push_back({dest, weight});
        } else {
            List<Pair<int, int>> l;
            l.push_back({dest, weight});
            edgesL.add(src, l);
        }
        edgesM(src, dest) = weight;
        edgesM(dest, src) = weight;
    }
};



#endif //GRAPH_H