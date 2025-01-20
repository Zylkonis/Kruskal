//
// Created by Teo on 12/01/2025.
//

#include "Kruskal.h"

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        std::cerr << "Nombre d'argument invalide." << std::endl;
        return -1;
    }
    const std::string graphIn = argv[1];

    const char* graphOut = "";
    if (argc == 3) {
        graphOut = argv[2];
    }
    Kruskal k;
    std::cout << "Kruskal L en route pour l'aventure verif maj2\n";
    k.kruskalL(graphIn, graphOut);
    std::cout << "\n\n\n\n KRUSKAL M\n\n";
    k.kruskalM(graphIn, graphOut);


    return 0;
}