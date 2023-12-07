//
// Created by Jo on 11/30/2023.
//

#ifndef FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_GRAPH_H
#define FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_GRAPH_H


#include "Vertex.h"
#include <algorithm>
#include <queue>

template<class T>
class Graph {
public:
    void addVertex(T newVertexData);
    void DFS(Vertex<T> *vertex, std::vector<Vertex<T>>* discoveredVertexes);
    Vertex<T> BFS(std::vector<Vertex<T>> *listToVisit, std::vector<Vertex<T>> *visited);
    Vertex<T>* getVertexById(int id) {
        return &vertices[id];
    }
    Vertex<T>* startVertex;
    Vertex<T>* goalVertex;

private:
    std::vector<Vertex<T>> vertices;

    bool contains(const std::vector<Vertex<T>>* vector, Vertex<T>& element); //helper function to find if element is in list

};


template<class T>
void Graph<T>::addVertex(T newVertexData) {
    Vertex<T> newVertex = {newVertexData};
    vertices.push_back(newVertex);
}


template<class T>
void Graph<T>::DFS(Vertex<T> *vertex, std::vector<Vertex<T>>* discoveredVertexes) { //TODO: early out if you find the target
    discoveredVertexes->push_back(*vertex);
    for(Vertex<T>* neighbor : vertex->neighbors) {
        if(!contains(discoveredVertexes, *neighbor)) {
            DFS(neighbor, discoveredVertexes);
        }
    }
}

template<class T>
Vertex<T> Graph<T>::BFS(std::vector<Vertex<T>>* listToVisit, std::vector<Vertex<T>>* visited) {
    visited->push_back(*startVertex);
    std::queue<Vertex<T>> q;
    q.push(*startVertex);
    while(!q.empty()) {
        Vertex<T> v = q.front();
        q.pop();
        if(v == *goalVertex) {
            return v;
        }
        for(auto neighbor : v.neighbors) {
            if(!contains(visited, *neighbor)) {
                visited->push_back(*neighbor);
                q.push(*neighbor);
            }
        }
    }
}



template<class T>
bool Graph<T>::contains(const std::vector<Vertex<T>>* vector, Vertex<T>& element) {
    return std::find(vector->begin(), vector->end(), element) != vector->end();
}

#endif //FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_GRAPH_H