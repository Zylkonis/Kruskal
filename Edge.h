//
// Created by Teo on 15/01/2025.
//

#ifndef EDGE_H
#define EDGE_H


class Edge {
private:
    int src;
    int dest;
    int weight;

public:
    Edge(const int s, const int d, const int w): src(s), dest(d), weight(w) {};

    bool operator<(const Edge edge) const {
        return weight < edge.getWeight();
    }
    bool operator>(const Edge edge) const {
        return weight > edge.getWeight();
    }
    bool operator==(const Edge edge) const {
        const bool res =
            ((src == edge.getSrc() && dest == edge.getDest()) || (src == edge.getDest() && dest == edge.getSrc()))  // graphe non-orienté
            && weight == edge.getWeight();
        return res;
    }


    int getSrc() const {
        return src;
    }

    int getDest() const {
        return dest;
    }

    int getWeight() const {
        return weight;
    }
};


#endif //EDGE_H
