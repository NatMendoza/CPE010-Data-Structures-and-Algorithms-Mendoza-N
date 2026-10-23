#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <functional>
#include "procedure.h"

const int SIZE = 100;

void displayArr(const int arr[], int size);

void timeDuration(const std::string& name,
                  const int original[], 
                  int size, 
                  std::function<void(int[])> sortFunc);

int main() {

    int arr[SIZE];
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    for (int i = 0; i < SIZE; i++) {
        arr[i] = std::rand() % 1000 + 1;
    }

    std::cout << "Unsorted Array:\n";
    displayArr(arr, SIZE);
    std::cout << "\n";

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
    std::vector<int> tempArr(original, original + size);

    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(tempArr.data());
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    std::cout << name << " Time: " << duration.count() << " ns\n";
    std::cout << "Sorted: ";
    displayArr(tempArr.data(), size);
    std::cout << "\n";
}








