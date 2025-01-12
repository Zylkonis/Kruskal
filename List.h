//
// Created by Teo on 12/01/2025.
//

#ifndef LIST_H
#define LIST_H

#include <iostream>


template <typename T>
class List {
    struct Element {
        T value;
        Element* next;

        Element(const T& value) : value(value), next(nullptr) {};
    };

    Element* head;
    Element* tail;
    size_t size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    ~List() {
        while (head) {
            pop_front();
        }
    }

    // Ajouter un élément à la fin
    void push_back(const T& value);

    // Ajouter un élément au début
    void push_front(const T& value);

    // Supprimer le premier élément
    void pop_front();

    // Obtenir la taille de la liste
    size_t get_size() const;

    // Vérifier si la liste est vide
    bool empty() const;
};


#endif //LIST_H
