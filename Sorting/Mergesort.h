//
// Created by jo.colomban on 2023-11-28.
//

#ifndef FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_MERGESORT_H
#define FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_MERGESORT_H


class Mergesort {
public:
    static void sort(int array[], int start, int end);
private:
    static void merge(int array[], int start, int half, int end);
};


#endif //FUTUREGAMES_ALGOSANDDATASTRUCTURESASSIGNEMENT_MERGESORT_H
