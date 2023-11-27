//
// Created by Jo on 11/27/2023.
//

#ifndef FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_QUICKSORT_H
#define FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_QUICKSORT_H


class Quicksort {
public:
    void quicksort(int array[], int start, int end);
private:
    int partition(int array[], int start, int end);
    static int pickPivot(int array[], int start, int end);
    static void swap(int array[], int a, int b);
};


#endif //FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_QUICKSORT_H
