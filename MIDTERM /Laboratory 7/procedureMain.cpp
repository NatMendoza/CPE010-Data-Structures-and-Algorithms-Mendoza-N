#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int SIZE = 100;

void displayArray(int arr[]);

int main() {

    // Create an array with unsorted list with 100 maximum size
    int unsortedArr[SIZE];

    // Use time(0) as seed
    std::srand(std::time(0)); 

    // Populate the array
    for (int i = 0; i < SIZE; i++) {
        unsortedArr[i] = std::rand() % 100 + 1;  // Random numbers between 1 and 100
    }
    std::cout << "Unsorted Array: " << std::endl;
    // Display the unsorted array
    displayArray(unsortedArr);

    // Bubble sort the array
    bubbleSort(unsortedArr, SIZE);
    std::cout << "Sorted Array: " << std::endl;
    displayArray(unsortedArr);

    // Selection sort the array
    selectionSort(unsortedArr, SIZE);
    std::cout << "Sorted Array: " << std::endl;
    displayArray(unsortedArr);

    // Insertion sort the array
    insertionSort(unsortedArr, SIZE);
    std::cout << "Sorted Array: " << std::endl;
    displayArray(unsortedArr);
}

void displayArray(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; 
}