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
        : rows(rows), cols(cols), data(rows, List<T>(cols, initialValue)) {}

    // Accesseur pour une cellule
    T& operator()(size_t row, size_t col);

    const T& operator()(size_t row, size_t col) const;

    // Obtenir le nombre de lignes
    size_t getRows() const { return rows; }

    // Obtenir le nombre de colonnes
    size_t getCols() const { return cols; }

    // Affichage de la matrice
    void afficher() const;
};


#endif //MATRIX_H
