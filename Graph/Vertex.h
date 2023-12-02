//
// Created by Jo on 11/30/2023.
//

#ifndef FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_VERTEX_H
#define FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_VERTEX_H

#include <vector>

template<class T>
class Vertex {
public:
    T data;
    void addEdge(Vertex<T>* newNeighbor);
    std::vector<Vertex<T>*> neighbors;

    bool operator==(const Vertex<T>& other) const {
        if (data == other.data) {
            return true;
        }
        return false;
    }
};

template<class T>
void Vertex<T>::addEdge(Vertex<T>* newNeighbor) {
    neighbors.push_back(newNeighbor);
}


#endif //FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_VERTEX_H
