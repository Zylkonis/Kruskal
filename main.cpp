//
// Created by Teo on 12/01/2025.
//

#include "Kruskal.h"

int main(int argc, char* argv[]) {

    std::cout << "argv[1] = " << argv[1] << std::endl;

    if (argc < 3 || argc > 4) { // L ou M puis fichier d'entrée puis de sortie
        std::cerr << "Nombre d'argument invalide." << std::endl;
        return -1;
    }
    const std::string graphIn = argv[2];

    const char* graphOut = "";
    if (argc == 4) {
        graphOut = argv[3];
    }

    Kruskal k;

    const std::string arg1 = argv[1];

    if (arg1 == "L") {
        k.kruskalL(graphIn, graphOut);
    } else if (arg1 == "M") {
        k.kruskalM(graphIn, graphOut);
    } else {
        std::cerr << "Mode de Kruskal invalide, il faut mettre L ou M" << std::endl;
    }

    return 0;
}