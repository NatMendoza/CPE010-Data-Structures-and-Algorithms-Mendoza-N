#ifndef QUEUELL_H
#define QUEUELL_H

#include <iostream>

template <typename T>
class qNode {
public:
    T data;
    qNode* next;
};

// Create a new node
template <typename T>
qNode<T>* new_node(T newData) {
    qNode<T>* newNode = new qNode<T>();
    newNode->data = newData;
    newNode->next = nullptr;

    return newNode;
}

// Enqueue
template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr) {

    qNode<T>* newNode = new_node(newData);

    if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }

    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}

// Dequeue
template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr) {

    if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        std::cout << "The queue is empty." << std::endl;
        return;
    }

    qNode<T>* deleteTemp = *frontPtr;

    // Only one node
    if ((*frontPtr)->next == nullptr) {
        *frontPtr = nullptr;
        *backPtr = nullptr;
        delete deleteTemp;
        return;
    }

    *frontPtr = (*frontPtr)->next;
    delete deleteTemp;
}

// Check if queue is empty
template <typename T>
bool isEmpty(qNode<T>** frontPtr, qNode<T>** backPtr) {
    return ((*frontPtr) == nullptr && (*backPtr) == nullptr);
}

// Display all elements
template <typename T>
void displayALL(qNode<T>** frontPtr, qNode<T>** backPtr) {

    if (isEmpty(frontPtr, backPtr)) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    qNode<T>* temp = *frontPtr;

    std::cout << "Queue Elements: ";

    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
}

#endif