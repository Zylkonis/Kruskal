//
// Created by Teo on 18/01/2025.
//

#ifndef MAP_H
#define MAP_H


#include <List.h>

template <typename K, typename V>
class Map {
private:

    struct Entry {
        K key;
        V value;

        Entry(const K& key, const V& value) : key(key), value(value) {}
    };

    List<Entry> entries;
    size_t size;

public:
    Map() : size(0){}

    // Ajouter ou mettre à jour une paire clé-valeur
    void add(const K& key, const V& value) {
        for (int i = 0; i < entries.get_size(); i++) {
            Entry entry = entries[i];
            if (entry.key == key) { // Si une clé est déjà présente
                entry.value = value; // Mise à jour de la valeur
                return;
            }
        }
        // Sinon ajout
        Entry e(key, value);

        entries.push_back(e);
        ++size;
    }

    // Obtenir la valeur associée à une clé
    V get(const K& key) const {
        for (int i = 0; i < entries.get_size(); i++) {
            Entry entry = entries[i];
            if (entry.key == key) {
                return entry.value;
            }
        }
        throw std::runtime_error("Key not found: " + key);
    }
    // Obtenir la valeur associée à une clé
    V& get(const K& key) {
        for (int i = 0; i < entries.get_size(); i++) {
            if (entries[i].key == key) {
                return entries[i].value;
            }
        }
        throw std::runtime_error("Key not found: " + key);
    }

    // Supprimer une paire clé-valeur
    void remove(const K& k) {
        int index = 0;
        for (Entry& entry : entries) {
            if (entry.key == k) {
                entries.remove(index);
                --size;
                return;
            }
            ++index;
        }
    }

    // Vérifier si une clé est présente
    bool containsKey(const K& key) const {
        for (int i = 0; i < entries.get_size(); i++) {
            Entry entry = entries[i];
            if (entry.key == key) {
                return true;
            }
        }
        return false;
    }

    // Obtenir la taille de la Map
    size_t getSize() const {
        return size;
    }
};



#endif //MAP_H
