#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>
#include <algorithm>
#include <functional>
#include "procedure.h" 

const int SIZE = 100;

void displayArr(const int arr[]);
void sortingDuration(const std::string& name, const int original[], std::function<void(int[])> sortFunc);

int main() {
    int unsortedArr[SIZE];
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    for (int i = 0; i < SIZE; i++) {
        unsortedArr[i] = std::rand() % 1000 + 1;
    }

    std::cout << "Unsorted Array:\n";
    displayArr(unsortedArr);
    std::cout << "\n";

    // Calling sortingDuration for each sorting algorithm
    sortingDuration("Shell Sort", unsortedArr, [](int arr[]) {
        shellSort(arr, SIZE);
    });

    sortingDuration("Merge Sort", unsortedArr, [](int arr[]) {
        mergeSort(arr, 0, SIZE - 1);
    });

    sortingDuration("Quick Sort", unsortedArr, [](int arr[]) {
        quickSort(arr, 0, SIZE - 1);
    });

    return 0;
}

void displayArr(const int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void sortingDuration(const std::string& name, const int original[], std::function<void(int[])> sortFunc) {
    int tempArr[SIZE];
    std::copy(original, original + SIZE, tempArr);

    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(tempArr);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Time taken by " << name << ": " << duration.count() << " microseconds\n";
    std::cout << "Sorted Array (" << name << "):\n";
    displayArr(tempArr);
    std::cout << "\n";
}