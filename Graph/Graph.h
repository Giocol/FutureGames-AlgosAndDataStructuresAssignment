//
// Created by Jo on 11/30/2023.
//

#ifndef FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_GRAPH_H
#define FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_GRAPH_H


#include "Vertex.h"
#include <algorithm>

template<class T>
class Graph {
public:
    void addVertex(T newVertexData);
    void DFS(Graph<T> *graph, Vertex<T> *vertex, std::vector<Vertex<T>>* discoveredVertexs);
    void BFS(Graph<T> *graph, Vertex<T> *initialVertex, std::vector<Vertex<T>> *listToVisit, std::vector<Vertex<T>> *visited);
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
void Graph<T>::DFS(Graph<T> *graph, Vertex<T> *vertex, std::vector<Vertex<T>>* discoveredVertexs) { //TODO: early out if you find the target
    discoveredVertexs->push_back(*vertex);
    for(Vertex<T>* neighbor : vertex->neighbors) {
        if(!contains(discoveredVertexs, *neighbor)) {
            DFS(graph, neighbor, discoveredVertexs);
        }
    }
}

template<class T>
void Graph<T>::BFS(Graph<T> *graph, Vertex<T>* initialVertex, std::vector<Vertex<T>>* listToVisit, std::vector<Vertex<T>>* visited) {
    visited->push_back(initialVertex);
    std::vector<Vertex<T>> newListToVisit;
    for(Vertex<T>* node : listToVisit) {
        visited->push_back(node);
        for(Vertex<T>* neighbor : node->neighbors) {
            if(!contains(visited, *neighbor)) {
                newListToVisit.push_back(neighbor);
            }
        }
    }
}



template<class T>
bool Graph<T>::contains(const std::vector<Vertex<T>>* vector, Vertex<T>& element) {
    return std::find(vector->begin(), vector->end(), element) != vector->end();
}

#endif //FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_GRAPH_H