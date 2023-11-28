//
// Created by Jo on 11/28/2023.
//

#ifndef FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_PROFILINGUTILS_H
#define FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_PROFILINGUTILS_H

#include <iostream>

namespace ProfilingUtils {
    void printElapsedTimeInNanos(long long time, int arraySize) {
        std::cout << "Sorted an array of size " << arraySize << "  in " << time <<  " nanoseconds" << std::endl;
    }
}

#endif //FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_PROFILINGUTILS_H
