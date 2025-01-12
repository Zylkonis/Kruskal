//
// Created by Teo on 12/01/2025.
//

#include "List.h"



// Ajouter un élément à la fin
template <typename T>
void List<T>::push_back(const T& value) {
    Element* newElement = new Element(value);
    if (!head) {
        head = tail = newElement;
    } else {
        tail->next = newElement;
        tail = newElement;
    }
    ++size;
}

// Ajouter un élément au début
template <typename T>
void List<T>::push_front(const T& value) {
        Element* newElement = new Element(value);
        if (!head) {
            head = tail = newElement;
        } else {
            newElement->next = head;
            head = newElement;
        }
        ++size;
    }

// Supprimer le premier élément
template <typename T>
void List<T>::pop_front() {
        if (!head) {
            std::cerr << "Liste vide, impossible d'utiliser pop_front()'.\n";
            return;
        }
        Element* temp = head;
        head = head->next;
        delete temp;
        --size;
        if (!head) {
            tail = nullptr;
        }
    }

// Obtenir la taille de la liste
template <typename T>
size_t List<T>::get_size() const {
        return size;
    }

// Vérifier si la liste est vide
template <typename T>
bool List<T>::empty() const {
        return size == 0;
    }