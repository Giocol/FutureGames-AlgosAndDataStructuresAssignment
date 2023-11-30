#include <chrono>
#include "Sorting/Quicksort.h"
#include "Sorting/Heapsort.h"
#include "Sorting/SimpleSorting.h"
#include "Utils/ArrayUtils.h"
#include "Utils/ProfilingUtils.h"
#include "Utils/ParsingUtils.h"
#include "Graph/Graph.h"

#define MAX_VALUE_IN_ARRAY 10000
#define ARRAY_SIZE 500

void measureSorting() {
    int testArray[ARRAY_SIZE];

    ArrayUtils::generateRandomArray(testArray, ARRAY_SIZE, MAX_VALUE_IN_ARRAY);
    ArrayUtils::printArray(testArray, ARRAY_SIZE);

    auto start = std::chrono::system_clock::now();
    Heapsort::sort(testArray, ARRAY_SIZE);
    auto end = std::chrono::system_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    long long timeElapsed = elapsed.count();

    std::cout << "Sorted array: " << std::endl;
    ArrayUtils::printArray(testArray, ARRAY_SIZE);
    ProfilingUtils::printElapsedTimeInNanos(timeElapsed, ARRAY_SIZE);


}

void graphTesting() {
    Graph<int> graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.getVertexById(0)->addEdge(*graph.getVertexById(1));
    graph.getVertexById(0)->addEdge(*graph.getVertexById(2));
    bool test = graph.getVertexById(0) == graph.getVertexById(1);
    std::vector<Vertex<int>> vertices;
    graph.DFS(&graph, graph.getVertexById(0), &vertices);
}

int main() {
    graphTesting();
    //measureSorting();
    Graph<int> graph;
    ParsingUtils::populateGraphFromFile("AssignmentNodes.txt", &graph);

    return 0;
}
