//
// Created by Teo on 12/01/2025.
//

#ifndef MATRIX_H
#define MATRIX_H



#include <iostream>
#include <List.h>
#include <stdexcept>

template <typename T>
class Matrix {
private:
    size_t rows;
    size_t cols;
    List<List<T>> data;

public:
    Matrix(size_t rows, size_t cols, const T& initialValue)
        : rows(rows), cols(cols) {
        for (int i = 0; i < rows; i++) {
            List<T> col;
            for (int j = 0; j < cols; j++) {
                col.push_back(initialValue);
            }
            data.push_back(col);
        }
    }

    // Accesseur pour une cellule
    T& operator()(size_t row, size_t col) {
        if (row >= rows || col >= cols) {
            throw std::out_of_range("Indice hors des limites de la matrice.");
        }
        return data[row][col];
    }

    const T& operator()(size_t row, size_t col) const {
        if (row >= rows || col >= cols) {
            throw std::out_of_range("Indice hors des limites de la matrice.");
        }
        return data[row][col];
    }

    // Obtenir le nombre de lignes
    size_t getRows() const { return rows; }

    // Obtenir le nombre de colonnes
    size_t getCols() const { return cols; }

    // Affichage de la matrice
    void afficher() const {
        for (int i = 0; i < rows; i++) {
            List<T> col = data[i];
            for (int j = 0; j < cols; j++) {
                T elem = col[j];
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

};


#endif //MATRIX_H
