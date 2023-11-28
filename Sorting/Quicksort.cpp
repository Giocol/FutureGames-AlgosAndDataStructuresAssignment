//
// Created by Jo on 11/27/2023.
//

#include "Quicksort.h"
void Quicksort::sort(int array[], int start, int end) {
    if(start < end) {
        int pivot = partition(array, start, end);
        sort(array, start, pivot - 1);
        sort(array, pivot + 1, end);
    }
}

int Quicksort::partition(int array[], int start, int end) {
    int pivot = pickPivot(array, start, end);
    int i = start-1; //temp pivot index

    for(int j = start; j < end; j++) {
        if(array[j] <= pivot) {
            i++; //increase the pivot index
            swap(array, i, j); //swap curr element with the element at the pivot index
        }
    }
    i++;
    swap(array, i, end);
    return i;
}

int Quicksort::pickPivot(int array[], int start, int end) {
    return array[end];
}


void Quicksort::swap(int array[], int a, int b) {
    int temp = array[b];
    array[b] = array[a];
    array[a] = temp;
}
