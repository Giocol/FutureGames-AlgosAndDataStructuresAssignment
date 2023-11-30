//
// Created by Jo on 11/30/2023.
//

#ifndef FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_PARSINGUTILS_H
#define FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_PARSINGUTILS_H

#include <fstream>
#include <iostream>
#include "../Graph/Graph.h"

namespace ParsingUtils {

    template<class T>
    void populateGraphFromMatrix(Graph<T>* graph, std::vector<std::vector<int>>* graphMatrix) {
        //function that is going to populate the graph itself from graphMatrix
    }

    template<class T>
    void populateGraphFromFile(const char* fileName, Graph<T>* graph) {
        std::vector<std::vector<int>> graphMatrix; //contains 0 for nodes, 1 for start, 2 for goal, -1 for walls
        std::ifstream file (fileName);
        if(file.is_open()) {
            std::string line;
            int i = 0;
            while(std::getline(file, line)) {
                size_t length = line.length();
                graphMatrix.emplace_back( );
                for(int j=0; j<length; j++) {
                    std::cout << line[j];
                    switch (line[j]) {
                        case 'X':
                            graphMatrix[i].push_back(-1);
                            break;
                        case 'S':
                            graphMatrix[i].push_back(1);
                            break;
                        case 'G':
                            graphMatrix[i].push_back(2);
                            break;
                        default:
                            graphMatrix[i].push_back(0);
                    }
                }
                std::cout << std::endl;
                i++;
            }
            graphMatrix.pop_back(); //hacky, removes the last element that is always created empty by the previous while loop
            file.close();
            populateGraphFromMatrix(graph, &graphMatrix);
        } else {
            std::cout << "unable to open file";
        }
    }


}

#endif //FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_PARSINGUTILS_H
