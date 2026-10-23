#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <random>

bool isUnique(const std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[i] == A[j]) {
                return false;
            }
        }
    }
    return true;
}

void run_unique_experiment(int n) {
    // Generate an array of unique integers (Worst-Case Scenario)
    std::vector<int> A(n);
    std::iota(A.begin(), A.end(), 1);

    auto start = std::chrono::high_resolution_clock::now();
    bool result = isUnique(A);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Input Size (N): " << n << " | Time: " << duration << " us | Result: " << (result ? "Unique" : "Not Unique") << std::endl;
}

int main() {
    run_unique_experiment(1000);
    run_unique_experiment(5000);
    run_unique_experiment(10000);
    return 0;
}

