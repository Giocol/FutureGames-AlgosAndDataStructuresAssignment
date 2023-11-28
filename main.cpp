#include "Sorting/Quicksort.h"
#include "Sorting/Mergesort.h"
#include "Utils/ArrayUtils.h"

#define MAX_VALUE_IN_ARRAY 10000
#define ARRAY_SIZE 50
int main() {
    int testArray[ARRAY_SIZE];
    generateRandomArray(testArray, ARRAY_SIZE, MAX_VALUE_IN_ARRAY);
    printArray(testArray, ARRAY_SIZE);
    Mergesort::sort(testArray, 0, ARRAY_SIZE - 1);
    printArray(testArray, ARRAY_SIZE);
    return 0;
}
