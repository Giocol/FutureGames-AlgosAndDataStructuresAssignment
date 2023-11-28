//
// Created by Jo on 11/27/2023.
//

#ifndef FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_QUICKSORT_H
#define FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_QUICKSORT_H


class Quicksort {
public:
    static void sort(int array[], int start, int end);
private:
    static int partition(int array[], int start, int end);
    static inline int pickPivot(int array[], int start, int end);
    static void swap(int array[], int a, int b);
};


#endif //FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_QUICKSORT_H
