//
// Created by Teo on 19/01/2025.
//

#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <Graph.h>
#include <string>
#include <fstream>
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
        if (parent[rootU] < parent[rootV]) {
            parent[rootV] = parent[rootU];
        } else {
            parent[rootU] = parent[rootV];
        }
    }

public:
    Kruskal() = default;

    // Algorithme de Kruskal sur les listes
    void kruskalL(const std::string &graphFile, const std::string &resFile = "") {
        double debut, fin;  // Test de temps
        debut = clock();
        const Graph graph = Graph::readGraphFromFile(graphFile);


        // Création et ajout des arêtes
        Map<int, List<Pair<int, int>>> edgesL = graph.getEdgesL();
        for (int i = 1; i <= graph.getOrder(); i++) {   // Parcours des sommets
            List<Pair<int, int>> lAdj = edgesL.get(i);

            for (int j = 0; j < lAdj.get_size(); j++) {    // Parcours des adjacences
                Pair<int, int> adj = lAdj[j];

                Edge e(i, adj.getFirst(), adj.getSecond());
                if (!isIn(e)) { // On ne veut pas de doublons
                    edgesRes.push_back(e);
                }
            }
        }
        std::cout << "affichage de lAdj: " << std::endl;
        for (int i = 0; i < edgesRes.get_size(); i++) {   // Parcours des sommets
            Edge e = edgesRes[i];
            std::cout << "{" << e.getSrc() << ", " << e.getDest() << ", " << e.getWeight() << "}" << std::endl;
        }


        // Tri des arêtes par poids croissant
        edgesRes.sort([](const Edge& a, const Edge& b) {
            return a < b;
        });
        std::cout << "affichage de edgesRes: " << std::endl;
        for (int i = 0; i < edgesRes.get_size(); i++) {
            std::cout << "{" << edgesRes[i].getSrc() << ", " << edgesRes[i].getDest() << ", " << edgesRes[i].getWeight() << "}" << std::endl;
        }

        for (int i = 0; i <= graph.getOrder(); i++) {
            parent.push_back(i);
        }

        List<Edge> acm; // Résultat : arêtes de l'arbre couvrant minimal

        // Parcours des arêtes triées
        for (int i = 0; i < edgesRes.get_size(); i++) {
            Edge edge = edgesRes[i];
            if (find(edge.getSrc()) != find(edge.getDest())) {
                acm.push_back(edge); // Ajout de l'arête à l'arbre couvrant
                unionF(find(edge.getSrc()), find(edge.getDest())); // Fusion des ensembles

                std::cout << "parent = {";
                for (int j = 0; j < parent.get_size(); j++) {
                    std::cout << parent[j] << ", ";
                }
                std::cout << "}" << std::endl;
            }
        }

        std::cout << "affichage du res: " << std::endl;
        for (int i = 0; i < acm.get_size(); i++) {
            std::cout << "{" << acm[i].getSrc() << ", " << acm[i].getDest() << ", " << acm[i].getWeight() << "}" << std::endl;
        }

        fin = clock();
        double temps_cpu = (fin-debut) / 1000 ;

        resultKruscal(acm, resFile, temps_cpu);
    }

    // Algorithme de Kruskal sur les matrices
    void kruskalM(const std::string &graphFile, const std::string &resFile = "") {
        double debut, fin;  // Test de temps
        debut = clock();
        const Graph graph = Graph::readGraphFromFile(graphFile);


        // Création et ajout des arêtes
        Matrix<int> edgesM = graph.getEdgesM();
        for (int i = 0; i < graph.getOrder(); i++) {
            for (int j = i; j < graph.getOrder(); j++) {
                if (edgesM(i, j) != 0) {
                    Edge e(i + 1, j + 1, edgesM(i, j));
                    if (!isIn(e)) { // On ne veut pas de doublons
                        edgesRes.push_back(e);
                    }
                }
            }
        }
        std::cout << "affichage de lAdj: " << std::endl;
        for (int i = 0; i < edgesRes.get_size(); i++) {   // Parcours des sommets
            Edge e = edgesRes[i];
            std::cout << "{" << e.getSrc() << ", " << e.getDest() << ", " << e.getWeight() << "}" << std::endl;
        }


        // Tri des arêtes par poids croissant
        edgesRes.sort([](const Edge& a, const Edge& b) {
            return a < b;
        });
        std::cout << "affichage de edgesRes: " << std::endl;
        for (int i = 0; i < edgesRes.get_size(); i++) {
            std::cout << "{" << edgesRes[i].getSrc() << ", " << edgesRes[i].getDest() << ", " << edgesRes[i].getWeight() << "}" << std::endl;
        }

        for (int i = 0; i <= graph.getOrder(); i++) {
            parent.push_back(i);
        }

        List<Edge> acm; // Résultat : arêtes de l'arbre couvrant minimal

        // Parcours des arêtes triées
        for (int i = 0; i < edgesRes.get_size(); i++) {
            Edge edge = edgesRes[i];
            if (find(edge.getSrc()) != find(edge.getDest())) {
                acm.push_back(edge); // Ajout de l'arête à l'arbre couvrant
                unionF(find(edge.getSrc()), find(edge.getDest())); // Fusion des ensembles

                std::cout << "parent = {";
                for (int j = 0; j < parent.get_size(); j++) {
                    std::cout << parent[j] << ", ";
                }
                std::cout << "}" << std::endl;
            }
        }

        std::cout << "affichage du res: " << std::endl;
        for (int i = 0; i < acm.get_size(); i++) {
            std::cout << "{" << acm[i].getSrc() << ", " << acm[i].getDest() << ", " << acm[i].getWeight() << "}" << std::endl;
        }

        fin = clock();
        double temps_cpu = (fin-debut) / 1000 ;

        resultKruscal(acm, resFile, temps_cpu);
    }

private:
    void resultKruscal(List<Edge> acm, const std::string &resFile, double temps) {
        bool connexe = true;
        int par = 1;
        while (connexe && par < parent.get_size() - 1) {
            if (parent[par] != parent[par + 1]) {
                connexe = false;
            }
            ++par;
        }

        int cost = 0;
        for (int i = 0; i < acm.get_size(); i++) {
            cost += acm[i].getWeight();
        }

        acm.sort([](const Edge& a, const Edge& b) {
            if (a.getSrc() == b.getSrc()) {
                return a.getDest() < b.getDest();
            }
            return a.getSrc() < b.getSrc();
        });

        if (resFile.empty()) {
            if (connexe) {
                std::cout << "LE GRAPHE EST CONNEXE" << std::endl;
            } else {
                std::cout << "LE GRAPHE N'EST PAS CONNEXE" << std::endl;
            }

            std::cout << "Total cost: " << cost << std::endl;

            std::cout << "affichage du res trie: " << std::endl;
            for (int i = 0; i < acm.get_size(); i++) {
                std::cout << "(" << acm[i].getSrc() << " -> " << acm[i].getDest() << " : " << acm[i].getWeight() << ")" << std::endl;
            }

            std::cout << "Temps CPU: " << temps << std::endl;
        }
        else {
            std::ofstream file("../" + resFile);
            if (file.is_open()) {
                if (connexe) {
                    file << "LE GRAPHE EST CONNEXE.\n";
                } else {
                    file << "LE GRAPHE N'EST PAS CONNEXE.\n";
                }

                file << "Coût total: " << cost << ".\n";

                for (int i = 0; i < acm.get_size(); i++) {
                    file << "(" << acm[i].getSrc() << " -> " << acm[i].getDest() << " : " << acm[i].getWeight() << ")\n";
                }

                file << "Temps CPU: " << temps << ".\n";

            } else {
                std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
            }

            file.close();
        }
    }
};

#endif //KRUSKAL_H
