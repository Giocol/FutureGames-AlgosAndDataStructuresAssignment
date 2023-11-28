//
// Created by Jo on 11/28/2023.
//

#ifndef FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_HEAPSORT_H
#define FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_HEAPSORT_H


class Heapsort {
public:
    static void sort(int array[], int size);
private:
    static void buildHeap(int array[], int size);
    static void heapify(int array[], int size, int i);
    static void swap(int *array, int a, int b);
};


#endif //FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_HEAPSORT_H
