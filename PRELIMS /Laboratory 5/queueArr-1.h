#ifndef QUEUEARR_H
#define QUEUEARR_H
#include <iostream>

template <typename T>
class queueArr {
private:
    T* q_arr;
    size_t q_capacity;
    size_t q_size;
    int q_front;
    int q_back;

public:
    queueArr(size_t capacity) : q_size(0), q_front(0), q_back(-1) {
        if (capacity == 0) capacity = 1;
        q_capacity = capacity;
        q_arr = new T[q_capacity];
    }

    queueArr(const queueArr& other)
        : q_capacity(other.q_capacity), q_size(other.q_size),
          q_front(other.q_front), q_back(other.q_back) {
        q_arr = new T[q_capacity];
        for (size_t i = 0; i < q_capacity; i++) {
            q_arr[i] = other.q_arr[i];
        }
    }

    queueArr& operator=(const queueArr& other) {
        if (this != &other) {
            delete[] q_arr;
            q_capacity = other.q_capacity;
            q_size = other.q_size;
            q_front = other.q_front;
            q_back = other.q_back;
            q_arr = new T[q_capacity];
            for (size_t i = 0; i < q_capacity; i++) {
                q_arr[i] = other.q_arr[i];
            }
        }
        return *this;
    }

    ~queueArr() {
        delete[] q_arr;
    }

    bool Empty() const { return q_size == 0; }
    bool Full() const { return q_size == q_capacity; }
    size_t Size() const { return q_size; }

    void Clear() {
        q_size = 0;
        q_front = 0;
        q_back = -1;
    }

    void enqueue(const T& value) {
        if (Full()) {
            std::cout << "Queue is Full\n";
            return;
        }
        q_back = (q_back + 1) % q_capacity;   
        q_arr[q_back] = value;
        q_size++;
    }

    T dequeue() {
        if (Empty()) {
            std::cout << "Queue is Empty\n";
            return T();
        }
        T value = q_arr[q_front];
        q_front = (q_front + 1) % q_capacity;
        q_size--;
        if (Empty()) Clear();   
        return value;
    }

    // Remove element at a specific offset/position relative to q_front
    bool removeAt(size_t index) {
        if (index >= q_size) {
            std::cout << "Invalid index position!\n";
            return false;
        }

        // Shift elements down to fill the removed position's slot
        for (size_t i = index; i < q_size - 1; i++) {
            int currentIdx = (q_front + i) % q_capacity;
            int nextIdx = (q_front + i + 1) % q_capacity;
            q_arr[currentIdx] = q_arr[nextIdx];
        }

        // Adjust back pointer and queue size
        q_back = (q_back - 1 + q_capacity) % q_capacity;
        q_size--;

        if (Empty()) Clear();
        return true;
    }

    void displayQueue() const {
        if (Empty()) {
            std::cout << "Queue is Empty\n";
            return;
        }

        std::cout << "\n===== Queue Contents =====\n";
        for (size_t i = 0; i < q_size; i++) {
            T current = q_arr[(q_front + i) % q_capacity];
            std::cout << "Index [" << i << "]: " << current << "\n";
            std::cout << "-----------------------------\n";
        }
    }
};
#endif