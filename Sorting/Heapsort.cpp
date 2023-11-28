//
// Created by Jo on 11/28/2023.
// Pseudocode from here: https://sites.cc.gatech.edu/classes/cs3158_98_fall/heapsort.html
//

#include <cmath>
#include "Heapsort.h"


void Heapsort::sort(int *array, int size) {
    buildHeap(array, size);
    for(int i = size - 1; i > 0; i--) {
        swap(array, 0, i);
        heapify(array, i, 0);
    }
}

void Heapsort::buildHeap(int *array, int size) {
    for(int i = size/2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }
}

void Heapsort::heapify(int *array, int size, int i) {
    int left = 2*i + 1; // representing the heap on an array in the "canonical" way
    int right = 2*i + 2;
    int largest = i;

    if(left < size && array[left] > array[i]) {
        largest = left;
    } else {
        largest = i;
    }
    if(right < size && array[right]>array[largest]) {
        largest = right;
    }
    if(largest != i) {
        swap(array, i, largest);
        heapify(array, size, largest);
    }
}

void Heapsort::swap(int array[], int a, int b) {
    int temp = array[b];
    array[b] = array[a];
    array[a] = temp;
}
