//
// Created by Teo on 12/01/2025.
//

#ifndef LIST_H
#define LIST_H

#include <functional>
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

    List(size_t size, T initValue) : size(size) {
        for (int i = 0; i < size; i++) {
            push_back(initValue);
        }
    }

    List(const List<T>& other) : head(nullptr), tail(nullptr), size(0) {
        Element* current = other.head;
        while (current) {
            push_back(current->value);
            current = current->next;
        }
    }

    ~List() {
        while (head) {
            pop_front();
        }
    }

    List<T>& operator=(const List<T>& other) {
        if (this != &other) {
            // Nettoyer les ressources existantes
            while (head) {
                pop_front();
            }
            // Copier les éléments de l'autre liste
            Element* current = other.head;
            while (current) {
                push_back(current->value);
                current = current->next;
            }
        }
        return *this;
    }

    T& operator[](const int index) {
        if (index < 0 || index >= static_cast<int>(size)) {
            throw std::out_of_range("Index hors limites");
        }

        Element* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }

    const T& operator[](const int index) const{
        if (index < 0 || index >= static_cast<int>(size)) {
            throw std::out_of_range("Index hors limites");
        }

        Element* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }

    // Ajouter un élément à la fin
    void push_back(const T& value) {
        auto* newElement = new Element(value);
        if (!head) {
            head = tail = newElement;
        } else {
            tail->next = newElement;
            tail = newElement;
        }
        ++size;
    }

    // Supprimer le premier élément
    void pop_front() {
        if (!head) {
            std::cerr << "Liste vide, impossible d'utiliser pop_front()'.\n";
            return;
        }

        Element* old = head;
        head = head->next;
        delete old;
        --size;

        if (!head) {
            tail = nullptr;
        }
    }

    // Obtenir la taille de la liste
    size_t get_size() const {
        return size;
    }

    // Vérifier si la liste est vide
    bool empty() const {
        return size == 0;
    }

    // Vérifier la présence d'un élément
    bool isIn(T value) {
        Element* e = head;
        for (int i = 0; i < size; i++) {
            if (value == e->value) {
                return true;
            }
            e = e->next;
        }
        return false;
    }

    // Méthode sort qui trie la liste grâce à une lambda fonction
    void sort(std::function<bool(const T&, const T&)> cmp) {
        if (size < 2) return; // Pas besoin de trier si la liste contient 0 ou 1 élément

        Element* sorted = nullptr; // Liste triée
        Element* current = head;

        while (current) {
            // Enlever l'élément de la liste actuelle
            Element* next = current->next;
            current->next = nullptr;

            // Insérer l'élément dans la liste triée
            if (!sorted || cmp(current->value, sorted->value)) {
                current->next = sorted;
                sorted = current;
            } else {
                Element* temp = sorted;
                while (temp->next && !cmp(current->value, temp->next->value)) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }

            current = next;
        }

        // Mettre à jour head et tail
        head = sorted;
        tail = head;
        while (tail && tail->next) {
            tail = tail->next;
        }
    }
};


#endif //LIST_H
