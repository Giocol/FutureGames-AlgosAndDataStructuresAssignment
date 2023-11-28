//
// Created by jo.colomban on 2023-11-28.
//

#ifndef FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_ARRAYUTILS_H
#define FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_ARRAYUTILS_H

#include <iostream>

void printArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << array[i] << '\t';
    }
    std::cout << std::endl;
}

#endif //FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_ARRAYUTILS_H
