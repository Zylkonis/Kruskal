//
// Created by Teo on 19/01/2025.
//

#ifndef KRUSKAL_H
#define KRUSKAL_H
#include <Graph.h>
#include <string>

#include "Edge.h"

class Kruskal {
private:
    List<Edge> edgesRes;
    List<int> parent;

    // Vérifier la présence d'une arête dans la liste
    bool isIn(const Edge edge) {
        return edgesRes.isIn(edge);
    }

    // Trouver le représentant de l'ensemble (Union-Find)
    int find(const int val) {
        if (parent[val] != val) {
            parent[val] = find(parent[val]); // Compression de chemin
        }
        return parent[val];
    }

    // Fusionner deux ensembles (Union-Find)
    void unionF(const int rootU, const int rootV) {
        parent[rootV] = rootU;
    }

public:
    Kruskal() = default;

    // Algorithme de Kruskal sur les listes
    void kruskalL(const std::string &graphFile, const std::string &resFile = nullptr) {
        std::cout << "graphFile = ";
        std::cout << graphFile << std::endl;
        const Graph graph = Graph::readGraphFromFile(graphFile);

        // Création et ajout des arêtes
        Map<int, List<Pair<int, int>>> edgesL = graph.getEdgesL();
        for (int i = 1; i <= graph.getOrder(); i++) {   // Parcours des sommets
            List<Pair<int, int>> lAdj = edgesL.get(i);

            for (int j = 1; j <= lAdj.get_size(); j++) {    // Parcours des adjacences
                Pair<int, int> adj = lAdj[j];

                Edge e(i, adj.getFirst(), adj.getSecond());
                if (!isIn(e)) { // On ne veut pas de doublons
                    edgesRes.push_back(e);
                }
            }
        }
        // Tri des arêtes par poids croissant
        edgesRes.sort([](const Edge& a, const Edge& b) {
            return a < b;
        });


        for (int i = 0; i <= graph.getOrder(); i++) {
            parent.push_back(i);
        }

        List<Edge> mst; // Résultat : arêtes de l'arbre couvrant minimal

        // Parcours des arêtes triées
        for (int i = 1; i <= edgesRes.get_size(); i++) {
            Edge edge = edgesRes[i];
            if (find(edge.getSrc()) != find(edge.getDest())) {
                mst.push_back(edge); // Ajout de l'arête à l'arbre couvrant
                unionF(edge.getSrc(), edge.getDest()); // Fusion des ensembles
            }
        }

        //return mst;
    }
};

#endif //KRUSKAL_H
