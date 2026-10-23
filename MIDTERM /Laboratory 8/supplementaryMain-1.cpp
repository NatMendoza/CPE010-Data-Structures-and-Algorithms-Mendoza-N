#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <functional>
#include "procedure.h"

const int SIZE = 15;

void displayArr(const int arr[], int size);

void timeDuration(const std::string& name,
                  const int original[], 
                  int size, 
                  std::function<void(int[])> sortFunc);

int main() {
    // Problem 2 Array
    int arr[SIZE] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};

    std::cout << "Original Array:\n";
    displayArr(arr, SIZE);
    std::cout << "===============================================\n";

    // Demonstration for Problem 1 Example: Hybrid QuickSort (uses ShellSort for sub-lists)
    timeDuration("Hybrid QuickSort (uses ShellSort for sub-lists)", arr, SIZE, [](int a[]) {
        hybridSort(a, 0, SIZE - 1);
    });

    // Performance comparison for Problem 2
    timeDuration("Shell Sort", arr, SIZE, [](int a[]) {
        shellSort(a, SIZE);
    });

    // Performance comparison for Problem 2 (Merge Sort)
    timeDuration("Merge Sort", arr, SIZE, [](int a[]) {
        mergeSort(a, 0, SIZE - 1);
    });


    return 0;
}

void displayArr(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void timeDuration(const std::string& name, 
                  const int original[], 
                  int size, 
                  std::function<void(int[])> sortFunc)
    {
    int tempArr[15];
    std::copy(original, original + size, tempArr);

    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(tempArr);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    std::cout << name << " Time: " << duration.count() << " ns\n";
    std::cout << "Sorted: ";
    displayArr(tempArr, size);
    std::cout << "\n";
}