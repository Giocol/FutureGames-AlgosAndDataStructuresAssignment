#include "Sorting/Quicksort.h"
#include "Sorting/Mergesort.h"
#include "Sorting/SimpleSorting.h"
#include "Utils/ArrayUtils.h"

#define MAX_VALUE_IN_ARRAY 10000
#define ARRAY_SIZE 50
int main() {
    int testArray[ARRAY_SIZE];
    ArrayUtils::generateRandomArray(testArray, ARRAY_SIZE, MAX_VALUE_IN_ARRAY);
    ArrayUtils::printArray(testArray, ARRAY_SIZE);
    Quicksort::sort(testArray, 0, ARRAY_SIZE - 1);
    ArrayUtils::printArray(testArray, ARRAY_SIZE);
    return 0;
}
