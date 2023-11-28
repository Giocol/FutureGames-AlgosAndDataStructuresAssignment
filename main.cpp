#include "Sorting/Quicksort.h"
#include "Sorting/Heapsort.h"
#include "Sorting/SimpleSorting.h"
#include "Utils/ArrayUtils.h"

#define MAX_VALUE_IN_ARRAY 10000
#define ARRAY_SIZE 500
int main() {
    int testArray[ARRAY_SIZE];
    ArrayUtils::generateRandomArray(testArray, ARRAY_SIZE, MAX_VALUE_IN_ARRAY);
    ArrayUtils::printArray(testArray, ARRAY_SIZE);
    Heapsort::sort(testArray, ARRAY_SIZE);
    ArrayUtils::printArray(testArray, ARRAY_SIZE);
    return 0;
}
