#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <cstddef>
#include <iostream>
#include <utility>

template<typename T>
void bubbleSort(T arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        for (size_t j = i + 1; j < arrSize; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template<typename T>
int routineSmallest(T arr[], int K, const int arrSize) {
    int position = K;
    T smallestElem = arr[K];
    
    for (int j = K + 1; j < arrSize; j++) {
        if (arr[j] < smallestElem) {
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;
}

template<typename T>
void selectionSort(T arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        int POS = routineSmallest(arr, i, static_cast<int>(arrSize));
        T temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
    }
}

template<typename T>
void insertionSort(T arr[], size_t arrSize) {
    size_t K = 1;
    
    while (K < arrSize) { 
        T temp = arr[K];
        int j = static_cast<int>(K) - 1;

        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = temp;
        K++;
    }
}

#endif