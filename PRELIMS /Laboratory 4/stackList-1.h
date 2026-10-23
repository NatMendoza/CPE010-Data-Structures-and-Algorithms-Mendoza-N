#ifndef STACKLIST_H
#define STACKLIST_H

#include <iostream>
#include <string>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
};

// GLOBAL POINTER FOR THE TOP OF THE STACK
template <typename T>
Node<T>* head = nullptr;

// PUSH
template <typename T>
void push(T newData) {
    Node<T>* newNode = new Node<T>();
    newNode->data = newData;

    newNode->next = head<T>;
    head<T> = newNode;
}

// POP
template <typename T>
T pop() {

    if (head<T> == nullptr) {
        std::cerr << "Stack Underflow: Cannot pop from an empty stack." << std::endl;
        return T();
    }

    Node<T>* temp = head<T>;
    T tempVal = temp->data;

    head<T> = head<T>->next;

    delete temp;

    return tempVal;
}

// ISEMPTY
template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

// TOP
template <typename T>
void Top() {

    if (head<T> == nullptr) {
        std::cout << "Stack is empty. No top element." << std::endl;
        return;
    }

    std::cout << "Top element: " << head<T>->data << std::endl;
}

// DISPLAY ALL
template <typename T>
void displayALL() {

    if (head<T> == nullptr) {
        std::cout << "Stack Underflow\n";
        return;
    }

    Node<T>* temp = head<T>;

    std::cout << "Stack Elements:\n";

    while (temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }

    std::cout << std::endl;
}

// ==========================================
// SUPPLEMENTARY ACTIVITY FUNCTIONS
// ==========================================

// CHECK IF OPENING SYMBOL
inline bool isOpening(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

// CHECK IF CLOSING SYMBOL
inline bool isClosing(char ch) {
    return ch == ')' || ch == ']' || ch == '}';
}

// CHECK IF SYMBOLS MATCH
inline bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// CHECK IF EXPRESSION IS BALANCED
inline bool isBalanced(const std::string& expression) {

    // Clear stack before checking
    while (!isEmpty<char>()) {
        pop<char>();
    }

    for (char ch : expression) {

        if (isOpening(ch)) {
            push<char>(ch);
        }
        else if (isClosing(ch)) {

            if (isEmpty<char>())
                return false;

            char topSymbol = pop<char>();

            if (!isMatching(topSymbol, ch))
                return false;
        }
    }

    return isEmpty<char>();
}

#endif // STACKLIST_H