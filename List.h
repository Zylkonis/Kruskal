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
        Element* head;
        Element* next;

        Element(const T& value, Element* head) : value(value), head(head), next(nullptr) {};
    };

    Element* head;
    Element* tail;
    size_t size;


    // Fonction de tri fusion pour trier la liste
    Element* merge_sort(Element* node, const std::function<bool(const T&, const T&)>& compare) {
        if (!node || !node->next) return node;

        // Diviser la liste en deux moitiés
        Element* mid = get_middle(node);
        Element* left = node;
        Element* right = mid->next;
        mid->next = nullptr;    // Séparation des deux "sous-listes"

        // Appliquer merge sort sur les deux moitiés
        left = merge_sort(left, compare);
        right = merge_sort(right, compare);

        // Fusionner les deux moitiés triées
        return merge(left, right, compare);
    }

    // Obtenir le milieu d'une liste
    Element* get_middle(Element* node) {
        if (!node) {
            return nullptr;
        }

        Element* res = head;
        const int iMid = size/2;
        int i = 0;
        while (i < iMid) {
            res = res->next;
            ++i;
        }
        return res;
    }

    // Fusionner deux listes triées
    Element* merge(Element* left, Element* right, const std::function<bool(const T&, const T&)>& compare) {
        if (!left) return right;
        if (!right) return left;

        if (compare(left->value, right->value)) {
            left->next = merge(left->next, right, compare);
            return left;
        } else {
            right->next = merge(left, right->next, compare);
            return right;
        }
    }

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    List(size_t size, T initValue) : size(size) {
        for (int i = 0; i < size; i++) {
            push_back(initValue);
        }
    }

    ~List() {
        while (head) {
            pop_front();
        }
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
        if (!head) {
            Element* newElement = new Element(value, newElement);
            head = tail = newElement;
        } else {
            Element* newElement = new Element(value, head);
            tail->next = newElement;
            tail = newElement;
        }
        ++size;
    }

    // Ajouter un élément au début
    void push_front(const T& value) {
        if (!head) {
            Element* newElement = new Element(value, newElement);
            head = tail = newElement;
        } else {
            Element* newElement = new Element(value, head);
            newElement->next = head;
            head = newElement;
        }
        ++size;
    }

    // Supprimer le premier élément
    Element* pop_front() {
        if (!head) {
            std::cerr << "Liste vide, impossible d'utiliser pop_front()'.\n";
            return nullptr;
        }
        Element* temp = head;
        head = head->next;
        --size;
        if (!head) {
            tail = nullptr;
        }
        return temp;
    }

    // Supprimer l'élément à l'index donné
    void remove(const int index) {
        if (index == 0) {
            head = head->next;
            Element* e = head;
            for (int i = 1; i < index; i++) {
                e->head = head;
                e = e->next;
            }
        } else {
            Element* e = head;
            for (int i = 1; i < index; i++) {
                e = e->next;
            }
            e->next = e->next->next;
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

    // Concatène deux listes
    void concat(List<T> L) {
        if (L.head == nullptr) return;
        if (!head) {
            head = L.head;
            tail = L.tail;
        } else {
            tail->next = L.head;
            tail = L.tail;
        }
        size += L.size;
    }

    // Tri avec une lambda fonction
    void sort(const std::function<bool(const T&, const T&)>& compare) {
        if (!head || !head->next) return; // Rien à trier si la liste est vide ou a un seul élément

        head = merge_sort(head, compare);

        // Mettre à jour le pointeur tail
        Element* current = head;
        while (current && current->next) {
            current = current->next;
        }
        tail = current;
    }
};


#endif //LIST_H
