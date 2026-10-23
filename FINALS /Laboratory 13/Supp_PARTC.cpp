#include <iostream>
#include <thread>

void merge(int arr[], int left, int mid, int right) {
    int temp[100];
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];    
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    std::thread T1(mergeSort, arr, left, mid);
    std::thread T2(mergeSort, arr, mid + 1, right);
    
    T1.join();
    T2.join();

    merge(arr, left, mid, right);
}


int main() {
    int arr[] = {12, 22, 4, 10, 2, 3, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Unsorted Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    mergeSort(arr, 0, size - 1);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
