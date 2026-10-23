#include <iostream>
#include <thread>
#include <mutex>

int total = 0;

std::mutex mtx;

void add(int value) {
    std::lock_guard<std::mutex> lock(mtx);
    total += value;
}


int main() {

    std::cout << "Display: " << total << std::endl;

    std::thread T1(add, 12);
    std::thread T2(add, 22);
    std::thread T3(add, 4);

    T1.join();
    std::cout << "Display of T1: " << total << std::endl;

    T2.join();
    std::cout << "Display of T2: " << total << std::endl;

    T3.join();
    std::cout << "Display of T3: " << total << std::endl;

    return 0;
}
