#ifndef PROCEDURE_H
#define PROCEDURE_H

#include <iostream>
#include <utility> // Included for std::swap

// ILO A.1 (Shell Sort)                                                     // VISUALIZE: Shell Sort Algorithm
template <typename T>
void shellSort(T arr[], int n) {                                            // Function to perform Shell Sort
    for (int gap = n / 2; gap > 0; gap /= 2) {                              // Start with a big gap, then reduce the gap
        for (int i = gap; i < n; i++) {                                     // Do a gapped insertion sort for this gap size
            T temp = arr[i];                                                // Store the current element to be compared
            int j;                                                          // Initialize j for the inner loop
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {        // Shift elements that are greater than temp to the right
                arr[j] = arr[j - gap];                                      // Move the element at j-gap to position j
            }
            arr[j] = temp;                                                  // Place temp (the original arr[i]) in its correct position
        }
    }
}
 
template <typename T>
void merge(T arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;                                             // Calculate the size of the left subarray
    int n2 = right - middle;                                                // Calculate the size of the right subarray

    T *L = new T[n1];                                                       // Create a temporary array for the left subarray
    T *R = new T[n2];                                                       // Create a temporary array for the right subarray      

    for (int i = 0; i < n1; i++)                                            // Copy data to temporary arrays L[] and R[]
        L[i] = arr[left + i];                                               // Copy the left subarray elements into L

    for (int j = 0; j < n2; j++)                                            // Copy the right subarray elements into R
        R[j] = arr[middle + 1 + j];                                         // Copy the right subarray elements into R

    int i = 0, j = 0, k = left;                                             // Initialize indices for L[], R[], and the merged subarray
    while (i < n1 && j < n2) {                                              // Merge the temporary arrays back into arr[left..right]
        if (L[i] <= R[j]) {                                                 // If the current element of L is less than or equal to the current element of R
            arr[k] = L[i];                                                  // Place the element from L into the merged array
            i++;                                                            // Move to the next element in L
        } else {
            arr[k] = R[j];                                                  // Place the element from R into the merged array
            j++;                                                            // Move to the next element in R
        }
        k++;                                                                // Move to the next position in the merged array
    }

    while (i < n1) {                                                        // Copy any remaining elements of L[], if there are any
        arr[k] = L[i];                                                      // Place the remaining element from L into the merged array
        i++;                                                                // Move to the next element in L
        k++;                                                                // Move to the next position in the merged array
    }

    while (j < n2) {                                                        // Copy any remaining elements of R[], if there are any
        arr[k] = R[j];                                                      // Place the remaining element from R into the merged array
        j++;                                                                // Move to the next element in R
        k++;                                                                // Move to the next position in the merged array
    }

    delete[] L;                                                             // Free the memory allocated for the temporary array L
    delete[] R;                                                             // Free the memory allocated for the temporary array R
}

// ILO A.2 (Merge Sort)                                                     // VISUALIZE: Merge Sort Algorithm
template <typename T>
void mergeSort(T arr[], int left, int right) {                              // Main recursive function for Merge Sort
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

// ILO A.3 (Quick Sort)                                                     // VISUALIZE: Quick Sort Algorithm
template <typename T>
void quickSort (T arr[], int low, int high) {                               // Function to perform Quick Sort
    if (low < high) {                                                       // If the array has more than one element
        T pivot = arr[high];                                                // Choose the last element as the pivot
        int i = (low - 1);                                                  // Index of the smaller element

        for (int j = low; j < high; j++) {                                  // Traverse through all elements
            if (arr[j] < pivot) {                                           // If the current element is smaller than the pivot
                i++;                                                        // Increment the index of the smaller element
                std::swap(arr[i], arr[j]);                                  // Swap the current element with the smaller element
            }
        }
        std::swap(arr[i + 1], arr[high]);                                   // Place the pivot in its correct position
        int pi = i + 1;                                                     // Index of the pivot

        quickSort(arr, low, pi - 1);                                        // Recursively sort elements before partition
        quickSort(arr, pi + 1, high);                                       // Recursively sort elements after partition
    }
}

// PROBLEM 1 EXAMPLE : Sorting left and right sub-lists using Shell Sort after partitioning with Quick Sort
void hybridSort(int arr[], int low, int high) {
    if (low < high) {
        // 1. Partition using Quick Sort logic
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1; // Pivot position

        // 2. Sort left and right sub-lists using Shell Sort
        int leftSize = pi - low;
        int rightSize = high - pi;

        if (leftSize > 1)  shellSort(&arr[low], leftSize);
        if (rightSize > 1) shellSort(&arr[pi + 1], rightSize);
    }
}

// Shell Sort to sort sub-lists (Qucik + Shell Sort) for Problem 1
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

#endif // PROCEDURE_H