/*
Problem: Median Finder
Name: Aditya Gautam
*/

#include <stdlib.h>

typedef struct {
    int arr[50005];
    int size;
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = malloc(sizeof(MedianFinder));
    obj->size = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {

    int i = obj->size - 1;

    while(i >= 0 && obj->arr[i] > num){
        obj->arr[i+1] = obj->arr[i];
        i--;
    }

    obj->arr[i+1] = num;
    obj->size++;
}

double medianFinderFindMedian(MedianFinder* obj) {

    int n = obj->size;

    if(n % 2)
        return obj->arr[n/2];

    return (obj->arr[n/2] + obj->arr[n/2 - 1]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}