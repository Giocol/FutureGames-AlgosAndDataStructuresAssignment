//
// Created by jo.colomban on 2023-11-28.
// pseudocode from https://textbooks.cs.ksu.edu/cc310/7-searching-and-sorting/16-merge-sort-pseudocode/
//

#include "Mergesort.h"

void Mergesort::sort(int array[], int start, int end) {
    if((end - start + 1) == 1) {
        return;
    }
    if((end - start + 1) == 2) {
        if(array[start] > array[end]) {
            int temp = array[start];
            array[start] = array[end];
            array[end] = temp;
        }
        return;
    }
    int half = (int) ((start + end)/2); //find middle
    sort(array, start, half); //sort first half
    sort(array, half+1, end); //sort second half
    merge(array, start, half, end);
}

//segfaults, must fix
void Mergesort::merge(int *array, int start, int half, int end) {
    int temp[end-start+1];
    int index1 = start;
    int index2 = half + 1;
    int newIndex = 0;
    while(index1 <= half && index2 <= end) {
        if(array[index1] < array[index2]) {
            temp[newIndex] = array[index1];
            index1++;
        } else {
            temp[newIndex] = array[index2];
            index2++;
        }
        newIndex++;
    }
    while(index1 <= half) {
        temp[newIndex] = array[index1];
        index1++;
        newIndex++;
    }
    while(index2 <= end) {
        temp[newIndex] = array[index2];
        index2 = index2;
        newIndex++;
    }
    for(int i = 0; i < end-start; i++) { //(end-start) is size(temp)-1
        array[start+i] = temp[i];
    }
}
