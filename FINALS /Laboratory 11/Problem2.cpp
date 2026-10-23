#include <iostream>
#include <chrono>

long long rpower(long long x, int n) {
    if (n == 0) return 1;
    return x * rpower(x, n - 1);
}

long long brpower(long long x, int n) {
    if (n == 0) return 1;
    if (n % 2 != 0) {
        long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else {
        long long y = brpower(x, n / 2);
        return y * y;
    }
}

void run_power_experiments(long long x, int n) {
    // Measure Linear Power
    auto start_r = std::chrono::high_resolution_clock::now();
    long long res_r = rpower(x, n);
    auto end_r = std::chrono::high_resolution_clock::now();
    auto dur_r = std::chrono::duration_cast<std::chrono::nanoseconds>(end_r - start_r).count();

    // Measure Binary Power
    auto start_br = std::chrono::high_resolution_clock::now();
    long long res_br = brpower(x, n);
    auto end_br = std::chrono::high_resolution_clock::now();
    auto dur_br = std::chrono::duration_cast<std::chrono::nanoseconds>(end_br - start_br).count();

    std::cout << "Exponent (N): " << n 
              << " | rpower: " << dur_r << " ns"
              << " | brpower: " << dur_br << " ns" << std::endl;
}

int main() {
    run_power_experiments(2, 100);
    run_power_experiments(2, 1000);
    run_power_experiments(2, 10000);
    return 0;
}

