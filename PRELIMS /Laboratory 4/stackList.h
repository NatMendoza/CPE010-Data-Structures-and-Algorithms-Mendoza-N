#ifndef STACKLIST_H
#define STACKLIST_H

#include <iostream>

template <typename T>
class Node {
    public:
    T data; // VALUE WE NEED TO STORE
    Node* next; // POINTER TO THE NEXT NODE
};

// GLOBAL POINTER FOR THE TOP OF THE STACK
template <typename T>
Node<T>* head = nullptr;

// OPERATTIONS FOR THE STACK

// PUSH
template <typename T>
void push(T newData) {
    // CREATE A NEW NODE AND ASSIGN THE newData
    Node<T>* newNode = new Node<T>();
    newNode->data = newData;

    // NEW NODE POINTS TO CURRENT TOP, THEN BECOMES THE NEW TOP
    newNode->next = head<T>;
    head<T> = newNode;
}

// POP

template <typename T>
T pop() {
    // CHECK IF THE STACK IS EMPTY:
    if (head<T> == nullptr) {
        std::cerr << "Stack Underflow: Cannot pop from an empty stack." << std::endl;
    }

    // SAVE THE CURRENT TOP NODE
    Node<T>* temp = head<T>;
    // STORE ITS DATA
    T tempVal = temp->data;

    // MOVE THE TOP POINTER TO THE NEXT NODE
    head<T> = head<T>->next;

    // FREE THE REMOVED NODE
    delete temp;

    // RETURN THE REMOVED VALUE
    return tempVal;
}

// isEmpty
template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

// Top
template <typename T>
void Top() {
    // ERROR CATCHING:
    if (head<T> == nullptr) {
        std::cout << "Stack is empty. No top element." << std::endl;
        return;
    }
    // DISPLAY THE TOP ELEMENT
    std::cout << "Top element: " << head<T>->data << std::endl;
}

// DISPLAY ALL
template <typename T>
void displayALL() {
    // ERROR CATCHING:
    if (head<T> == nullptr) {
        std::cout << "Stack Underflow\n" << std::endl;
        return;
    }

    // TRAVERSE THE STACK AND DISPLAY ALL ELEMENTS
    Node<T>* temp = head<T>;
    std::cout << "Stack elements: \n";
    while (temp != nullptr) {
        std::cout << temp->data << " \n";
        temp = temp->next;
    }
    std::cout << std::endl;
}

#endif // STACKLIST_H