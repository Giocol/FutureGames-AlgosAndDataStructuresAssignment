//
// Created by Jo on 11/30/2023.
//

#ifndef FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_PARSINGUTILS_H
#define FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_PARSINGUTILS_H

#include <fstream>
#include <iostream>
#include "../Graph/Graph.h"

namespace ParsingUtils {

    struct vec2
    {
        int x;
        int y;

        bool operator==(const vec2 other) const {
            if (x == other.x && y == other.y) {
                return true;
            }
            return false;
        }
    };

    int getVertexIdFromCoords(int i, int j, size_t size) { //simple function to linearize indexes on  a 2d matrix, size is the length of the "parent" vector/array
        return i*size + j;
    }

    template<class T>
    void connectVertexesFromMatrix(Graph<T>* graph, std::vector<std::vector<int>>* graphMatrix) {
        //function that is going to populate each vertex's neighbors from graphMatrix
        int currId = 0;
        size_t graphMatrixSize = graphMatrix->size();
        for(int i = 0; i<graphMatrixSize; i++) {
            for(int j = 0; j<(*graphMatrix)[i].size(); j++) {
                if(i > 0 && (*graphMatrix)[i-1][j] != -1) {//element to the left, if it exists and it's not a wall (walls are marked as -1 in the graphMatrix)
                    graph->getVertexById(currId)->addEdge(graph->getVertexById(getVertexIdFromCoords(i-1, j, graphMatrixSize)));
                }
                if(j > 0 && (*graphMatrix)[i][j-1] != -1) { //element below
                    graph->getVertexById(currId)->addEdge(graph->getVertexById(getVertexIdFromCoords(i, j-1, graphMatrixSize)));
                }
                if((i < (*graphMatrix)[i].size() -1) && (*graphMatrix)[i+1][j] != -1) { //element to the right
                    graph->getVertexById(currId)->addEdge(graph->getVertexById(getVertexIdFromCoords(i+1, j, graphMatrixSize)));
                }
                if((j < (*graphMatrix)[i].size() -1) && (*graphMatrix)[i][j+1] != -1) { //element above
                    graph->getVertexById(currId)->addEdge(graph->getVertexById(getVertexIdFromCoords(i, j+1, graphMatrixSize)));
                }
                currId++;
            }
        }
    }

    template<class T>
    void populateGraphFromFile(const char* fileName, Graph<T>* graph) {
        std::vector<std::vector<int>> graphMatrix; //contains 0 for nodes, 1 for start, 2 for goal, -1 for walls
        std::ifstream file (fileName);
        int startVertexPosition;
        int goalVertexPosition;
        if(file.is_open()) {
            std::string line;
            int i = 0;
            while(std::getline(file, line)) {
                size_t length = line.length();
                graphMatrix.emplace_back( );
                for(int j=0; j<length; j++) {
                    std::cout << line[j];
                    vec2 data = {i, j};
                    graph->addVertex(data); //since the file doesn't have any actual data, i'm passing a vec2 containing its coords
                    switch (line[j]) {
                        case 'X':
                            graphMatrix[i].push_back(-1);
                            break;
                        case 'S':
                            graphMatrix[i].push_back(1);
                            startVertexPosition = getVertexIdFromCoords(i, j, length);
                            break;
                        case 'G':
                            graphMatrix[i].push_back(2);
                            goalVertexPosition = getVertexIdFromCoords(i, j, length);
                            break;
                        default:
                            graphMatrix[i].push_back(0);
                            break;
                    }
                }
                std::cout << std::endl;
                i++;
            }
            graphMatrix.pop_back(); //hacky, removes the last element that is always created empty by the previous while loop
            file.close();
            graph->startVertex = graph->getVertexById(startVertexPosition);
            graph->goalVertex = graph->getVertexById(goalVertexPosition);
            connectVertexesFromMatrix(graph, &graphMatrix);
        } else {
            std::cout << "unable to open file";
        }
    }


}

#endif //FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_PARSINGUTILS_H
