//
// Created by Jo on 11/30/2023.
//

#ifndef FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_GRAPH_H
#define FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_GRAPH_H


#include "Vertex.h"
#include "../Utils/ParsingUtils.h"
#include <algorithm>
#include <queue>
#include <set>

template<class T>
class Graph {
public:
    void addVertex(T newVertexData);
    void DFS(Vertex<T> *startVertex, std::vector<Vertex<T>>* discoveredVertexes);
    Vertex<T> BFS(std::vector<Vertex<T>> *visited);
    void A_star(Vertex<T> *start, Vertex<T> *goal);
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
void Graph<T>::DFS(Vertex<T> *startVertex, std::vector<Vertex<T>>* discoveredVertexes) { //TODO: early out if you find the target
    discoveredVertexes->push_back(*startVertex);
    for(Vertex<T>* neighbor : startVertex->neighbors) {
        if(!contains(discoveredVertexes, *neighbor)) {
            DFS(neighbor, discoveredVertexes);
        }
    }
}

template<class T>
Vertex<T> Graph<T>::BFS(std::vector<Vertex<T>>* visited) {
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
void Graph<T>::A_star(Vertex<T>* start, Vertex<T>* goal) {
    struct CompareVertexes { //Using euclidian distance from the goal as a cost metric since my vertexes don't have a cost heuristic.
        // ideally it would not be like that since this only works with Graph<vec2> (yes this is pretty much Djistrka in a trench-coat)
        const Vertex<T>* goal;

        explicit CompareVertexes(const Vertex<T>* goal) : goal(goal) {}

        bool operator()(const Vertex<T>* a, const Vertex<T>* b) const {
            int dx_a = a->data.x - b->data.x;
            int dy_a = a->data.y - b->data.y;
            int dx_b = goal->data.x - b->data.x;
            int dy_b = goal->data.y - b->data.y;

            return (dx_a * dx_a + dy_a * dy_a) > (dx_b * dx_b + dy_b * dy_b);
        }
    };

    std::priority_queue<Vertex<T>*, std::vector<Vertex<T>*>, CompareVertexes> openSet{CompareVertexes{goal}};
    std::set<Vertex<T>*> visited;

    openSet.push(start);

    while (!openSet.empty()) {
        Vertex<T>* current = openSet.top();
        openSet.pop();

        if (current == goal) {
            std::cout << "Path found." << std::endl;
            return;
        }

        visited.insert(current);

        for (Vertex<T>* neighbor : current->neighbors) {
            if (visited.find(neighbor) == visited.end()) {
                openSet.push(neighbor);
            }
        }
    }

    std::cout << "No path found." << std::endl;
}

template<class T>
bool Graph<T>::contains(const std::vector<Vertex<T>>* vector, Vertex<T>& element) {
    return std::find(vector->begin(), vector->end(), element) != vector->end();
}

#endif //FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_GRAPH_H