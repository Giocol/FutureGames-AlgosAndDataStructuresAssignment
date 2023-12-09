#include <chrono>
#include "Sorting/Quicksort.h"
#include "Sorting/Heapsort.h"
#include "Sorting/SimpleSorting.h"
#include "Utils/ArrayUtils.h"
#include "Utils/ProfilingUtils.h"
#include "Utils/ParsingUtils.h"
#include "Graph/Graph.h"

#define MAX_VALUE_IN_ARRAY 10000
#define ARRAY_SIZE 5000
#define SAMPLES 10

void measureSorting() {
    int testArray[ARRAY_SIZE];

    //ArrayUtils::generateSortedArray(testArray, ARRAY_SIZE);
    //ArrayUtils::printArray(testArray, ARRAY_SIZE);

    for(int i=0; i<SAMPLES; i++) {
        ArrayUtils::generateRandomArray(testArray, ARRAY_SIZE, MAX_VALUE_IN_ARRAY);
        //ArrayUtils::printArray(testArray, ARRAY_SIZE);

        auto start = std::chrono::system_clock::now();

        //Quicksort::sort(testArray, 0,  ARRAY_SIZE);
        //Heapsort::sort(testArray,  ARRAY_SIZE);
        //SimpleSorting::selectionSort(testArray, ARRAY_SIZE);
        //SimpleSorting::bubbleSort(testArray, ARRAY_SIZE);
        //SimpleSorting::insertionSort(testArray, ARRAY_SIZE);
        auto end = std::chrono::system_clock::now();

        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        long long timeElapsed = elapsed.count();
        //std::cout << timeElapsed << std::endl;
        ProfilingUtils::printElapsedTimeInNanos(timeElapsed, ARRAY_SIZE);
    }
    std::cout << "Sorted array: " << std::endl;
    ArrayUtils::printArray(testArray, ARRAY_SIZE);
}

void graphTesting() {
    Graph<ParsingUtils::vec2> graph;
    ParsingUtils::populateGraphFromFile("AssignmentNodes.txt", &graph);
    std::vector<Vertex<ParsingUtils::vec2>> vertices;

    auto start = std::chrono::system_clock::now();

    //graph.DFS(graph.startVertex, &vertices);
    //graph.BFS(&vertices);
    //graph.A_star(graph.startVertex, graph.goalVertex);

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    long long timeElapsed = elapsed.count();

    std::cout << "Found goal node in " << elapsed.count() << " nanoseconds" << std::endl;
}

int main() {
    graphTesting();
    //measureSorting();

    return 0;
}
