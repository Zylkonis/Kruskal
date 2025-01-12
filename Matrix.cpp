//
// Created by Teo on 12/01/2025.
//

#include "Matrix.h"

// Accesseur pour une cellule
template <typename T>
T& Matrix<T>::operator()(size_t row, size_t col) {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Indice hors des limites de la matrice.");
    }
    return data[row][col];
}

template <typename T>
const T& Matrix<T>::operator()(size_t row, size_t col) const {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Indice hors des limites de la matrice.");
    }
    return data[row][col];
}

// Affichage de la matrice
template <typename T>
void Matrix<T>::afficher() const {
    for (const auto& row : data) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}