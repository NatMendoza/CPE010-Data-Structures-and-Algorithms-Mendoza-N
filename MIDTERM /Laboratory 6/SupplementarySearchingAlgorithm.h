#include "supplementaryNode.h"
#include <iostream>

#ifndef SUPPLEMENTARYSEARCHINGALGO_H
#define SUPPLEMENTARYSEARCHINGALGO_H

// Sequential search for Problem 1 (Array approach)
template<typename T>
void linearSearchArray(T array[], int size, T item) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (array[i] == item) {
            std::cout << "[Array] Key '" << item << "' found at index " << i 
                      << " after " << comparisons << " comparison(s).\n";
            return;
        }
    }
    std::cout << "[Array] Key '" << item << "' not found after " << comparisons << " comparison(s).\n";
}

// Sequential search for Problem 1 (Linked List approach)
template<typename T>
void linearSearchLinkedList(Node<T>* head, T item) {
    int comparisons = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        comparisons++;
        if (current->data == item) {
            std::cout << "[Linked List] Key '" << item << "' found after " 
                      << comparisons << " comparison(s).\n";
            return;
        }
        current = current->next;
    }
    std::cout << "[Linked List] Key '" << item << "' not found after " 
              << comparisons << " comparison(s).\n";
}

// Problem 2: Sequential search modified to count total repeating occurrences of 'k'
template<typename T>
int countOccurrences(T array[], int size, T k) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == k) {
            count++;
        }
    }
    return count;
}

// Problem 3: Standard Iterative Binary Search
template<typename T>
void binarySearchIterative(T data[], int size, T dataFind) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (dataFind == data[middle]) {
            std::cout << "Key '" << dataFind << "' found at index " << middle << ".\n";
            return;
        }
        else if (dataFind < data[middle]) {
            high = middle - 1;
        }
        else {
            low = middle + 1;
        }
    }

    std::cout << "Key '" << dataFind << "' was not found.\n";
}

// Problem 4: Recursive Binary Search
template<typename T>
void binarySearchRecursive(T data[], int low, int high, T dataFind) {
    if (low > high) {
        std::cout << "Key '" << dataFind << "' was not found.\n";
        return;
    }

    int middle = low + (high - low) / 2;

    if (dataFind == data[middle]) {
        std::cout << "Key '" << dataFind << "' found at index " << middle << ".\n";
        return;
    }
    else if (dataFind < data[middle]) {
        binarySearchRecursive(data, low, middle - 1, dataFind);
    }
    else {
        binarySearchRecursive(data, middle + 1, high, dataFind);
    }
}

#endif