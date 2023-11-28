//
// Created by jo.colomban on 2023-11-28.
//

#ifndef FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_SIMPLESORTING_H
#define FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_SIMPLESORTING_H

namespace SimpleSorting {
    void swap(int array[], int a, int b) {
        int temp = array[b];
        array[b] = array[a];
        array[a] = temp;
    }

    void insertionSort(int array[], int size) {
        for (int i = 0; i < size; ++i) {
            int j = i;
            while(j > 0 && array[j] < array[j-1]) {
                swap(array, j, j-1);
                j--;
            }
        }
    }

    void bubbleSort(int array[], int size) {
        for(int i = 0; i < size -1; i++) {
            for(int j = 0; j < size - i - 1; j++) {
                if(array[j] > array[j+1]) {
                    swap(array, j, j+1);
                }
            }
        }
    }

    void selectionSort(int array[], int size) {
        for(int i = 0; i < size; i++) {
            int lowestValueIndex = i;
            for(int j = i+1; j<size; j++) {
                if(array[j] < array[lowestValueIndex]) {
                    lowestValueIndex = j;
                }
            }
            if(array[i] != array[lowestValueIndex]) {
                swap(array, i, lowestValueIndex);
            }
        }
    }
}

#endif //FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_SIMPLESORTING_H
