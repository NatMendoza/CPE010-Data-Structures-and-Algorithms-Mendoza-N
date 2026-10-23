#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <functional>

int linearSearch(const std::vector<int>& arr, int target);
int binarySearch(const std::vector<int>& arr, int target);
void displayArr(const std::vector<int>& arr, int size);
void timeSearch(const std::string& name, const std::vector<int>& arr, int target, std::function<int(const std::vector<int>&, int)> searchFunc) ;

int main() {
    const int SIZE = 1000;
    std::vector<int> data(SIZE);
    std::iota(data.begin(), data.end(), 1);
    int target = 99;

    std::cout << "Target: " << target << " in " << SIZE << " elements.\n\n";

    // Benchmark using your functions
    timeSearch("Linear Search", data, target, linearSearch);
    timeSearch("Binary Search", data, target, binarySearch);

    return 0;
}

int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void displayArr(const std::vector<int>& arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void timeSearch(const std::string& name, 
                const std::vector<int>& arr, 
                int target, 
                std::function<int(const std::vector<int>&, int)> searchFunc) 
{
    auto start = std::chrono::high_resolution_clock::now();
    int result = searchFunc(arr, target);
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::high_resolution_clock::now() - start).count();

    std::cout << name << " -> Index: " << result << " | Time: " << duration << " ns\n";
}