//
// Created by Teo on 12/01/2025.
//

#include "Kruskal.h"

int main() {
    std::cout << "Debut du programme" << std::endl;

    const std::string graphFile = "testGraph";
    Kruskal k;
    k.kruskalL(graphFile);

    return 0;
}
