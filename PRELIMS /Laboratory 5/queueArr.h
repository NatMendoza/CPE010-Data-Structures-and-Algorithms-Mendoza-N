#ifndef QUEUEARR_H
#define QUEUEARR_H
# include <iostream>

// Array-Based Circular Queue
template <typename T>
class queueArr {
    private:
        // POINTER TO DYNAMICALLY ALLOCATE ARRAY
        T* q_arr;

        // MAXIMUM NUMBER OF ELEMENTS A QUEUE CAN HOLD
        size_t q_capacity;

        // CURRENT NUMBER OF ELEMENTS IN THE QUEUE
        size_t q_size;

        // INDEX OF THE FRONT ELEMENT IN THE QUEUE
        int q_front;

        // INDEX OF THE BACK ELEMENT IN THE QUEUE
        int q_back;

    public:

    // CONSTRUCTOR
    queueArr(size_t capacity) : q_capacity(capacity), q_size(0), q_front(0), q_back(-1) {
        // DYNAMICALLY ALLOCATE MEMORY FOR THE QUEUE ARRAY
        q_arr = new T[q_capacity];
    }

    // COPY CONSTRUCTOR
    queueArr(const queueArr& other) : q_capacity(other.q_capacity), q_size(other.q_size), q_front(other.q_front), q_back(other.q_back) {
        // DYNAMICALLY ALLOCATE MEMORY FOR THE QUEUE ARRAY
        q_arr = new T[q_capacity];
        // COPY ELEMENTS FROM OTHER QUEUE
        for (size_t i = 0; i < q_size; ++i) {
            q_arr[(q_front + i) % q_capacity] = other.q_arr[(other.q_front + i) % other.q_capacity];
        }
    }

    // COPY ASSIGNMENT OPERATOR
    queueArr& operator=(const queueArr& other) {
        if (this != &other) {
            // DEALLOCATE CURRENT ARRAY
            delete[] q_arr;

            // COPY CAPACITY AND SIZE
            q_capacity = other.q_capacity;
            q_size = other.q_size;
            q_front = other.q_front;
            q_back = other.q_back;

            // DYNAMICALLY ALLOCATE MEMORY FOR THE QUEUE ARRAY
            q_arr = new T[q_capacity];
            // COPY ELEMENTS FROM OTHER QUEUE
            for (size_t i = 0; i < q_size; ++i) {
                q_arr[(q_front + i) % q_capacity] = other.q_arr[(other.q_front + i) % other.q_capacity];
            }
        }
        return *this;
    }

    // DESTRUCTOR
    ~queueArr() {
        // DEALLOCATE MEMORY FOR THE QUEUE ARRAY
        delete[] q_arr;
    }

    // QUEUE OPERATIONS
    bool Empty();
    bool Full();
    size_t Size();
    void Clear();
    T Front();
    T Back();
    void enqueue(T value);
    T dequeue();
};

// Empty()
template <typename T>
bool queueArr<T>::Empty() {
    // CHECK IF EMPTY
    return q_size == 0;
}

// Full()
template <typename T>
bool queueArr<T>::Full() {
    // CHECK IF REACHES MAX CAPACITY
    return q_size == q_capacity;
}

// Size()
template <typename T>
size_t queueArr<T>::Size() {
    // RETURN CURRENT SIZE OF QUEUE
    return q_size;
}

// Front()
template <typename T>
T queueArr<T>::Front() {
    // Check if the queue is empty
    if (Empty()) {
        std::cout << "Queue is Empty\n";
        return T(); // Return default value of type T
    }
    // Return the front
    return q_arr[q_front];
}

// Back()
template <typename T>
T queueArr<T>::Back() {
    // Check if the queue is empty
    if (Empty()) {
        std::cout << "Queue is Empty\n";
        return T(); // Return default value of type T
    }
    // Return the back
    return q_arr[q_back];
}

// Clear()
template <typename T>
void queueArr<T>::Clear() {
    // Reset the queue to its initial state
    q_size = 0;
    q_front = 0;
    q_back = -1; // Set back to -1 since there are no elements
}

// Enqueue()
template <typename T>
void queueArr<T>::enqueue(T value) {
    // Check if the queue is full
    if (Full()) {
        std::cout << "Queue is Full\n";
        return;
    }
    // Increment the back
    q_back = (q_back + 1) % q_capacity;   
    // Add the new value to the back of the queue
    q_arr[q_back] = value;
    // Increment the size of the queue
    q_size++;
}

// Dequeue()
template <typename T>
T queueArr<T>::dequeue() {
    // Check if the queue is empty
    if (Empty()) {
        std::cout << "Queue is Empty\n";
        return T(); // Return default value of type T
    }
    // Store the front value
    T value = q_arr[q_front];
    // Increment the front index in a circular manner
    q_front = (q_front + 1) % q_capacity;
    // Decrement the size of the queue
    q_size--;
    // Reset the indexes
    if (Empty()) Clear();   
    // Return the dequeued value
    return value;
}

#endif // QUEUEARR_H