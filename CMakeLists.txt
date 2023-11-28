cmake_minimum_required(VERSION 3.26)
project(FutureGames_AlgosAndDataStructuresAssignement)

set(CMAKE_CXX_STANDARD 17)

add_executable(FutureGames_AlgosAndDataStructuresAssignement main.cpp
        Sorting/Quicksort.h
        Sorting/Quicksort.cpp
        Utils/ArrayUtils.h
        Sorting/Mergesort.h
        Sorting/Mergesort.cpp
)
