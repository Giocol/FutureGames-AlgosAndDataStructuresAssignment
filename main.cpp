#include <iostream>
#include "Sorting/Quicksort.h"

int main() {
    Quicksort quickSorter;
    int testArray[] = {5, 2, 1, 8, 23};

    int n=sizeof(testArray)/sizeof(testArray[0]);

    quickSorter.quicksort(testArray, 0, n-1);
    std::cout << testArray[0] << std::endl;
    return 0;
}
