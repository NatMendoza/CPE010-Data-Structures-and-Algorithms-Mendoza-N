#ifndef SINGLY_LL_H
#define SINGLY_LL_H

#include <iostream>

/* Node Creation */
template <typename N>
class SingleList {
public:
    N data; // This contains the data variable to be stored in the Node.
    SingleList<N>* next = nullptr;
};

/* List Traversal */
template <typename N>
void ListTraversal(SingleList<N>* head) {

    while (head != nullptr) {
        // PRINT data of N
        std::cout << head->data << "-->";

        // GO NEXT NODE N := next
        head = head->next;
    }

    std::cout << std::endl;
}

/* Insert at Head */
template <typename N>
void sllinsertHead(N newData, SingleList<N>** currentHead) {

    // 1. Allocate memory
    SingleList<N>* newNode = new SingleList<N>;

    // 2. Put data into the new node
    newNode->data = newData;

    // 3. Set next to the current head
    newNode->next = *currentHead;

    // 4. Make the new node the new head
    *currentHead = newNode;
}

/* General Insert */
template <typename N>
void sllGeneralInsert(N newData, SingleList<N>* prevNode) {

    if (prevNode == nullptr) {
        std::cout << "Previous Value cannot be null" << std::endl;
        return;
    }

    SingleList<N>* newNode = new SingleList<N>;

    newNode->data = newData;

    newNode->next = prevNode->next;

    prevNode->next = newNode;
}

/* Insert at End */
template <typename N>
void sllinsertEnd(N newData, SingleList<N>** head) {

    // 1. Allocate a new node
    SingleList<N>* newNode = new SingleList<N>;

    // 2. Store data in new node
    newNode->data = newData;

    // 3. Point to null
    newNode->next = nullptr;

    // 4. Dereference the head node
    SingleList<N>* currentNode = *head;

    // If the list is empty
    if (currentNode == nullptr) {
        *head = newNode;
        return;
    }

    // 5. Traverse the list
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }

    // 6. Point the next of the current node to the new node
    currentNode->next = newNode;
}

/* Delete Node */
template <typename N>
    void sllDeleteNode(N findData, SingleList<N>** head) {

    // If there is nothing to delete
    if (*head == nullptr) {
        return;
    }

    SingleList<N>* currNode = *head;
    SingleList<N>* prevNode = nullptr;

    // Search for the node
    while (currNode != nullptr && currNode->data != findData) {

        prevNode = currNode;

        currNode = currNode->next;
    }

    // If data was not found
    if (currNode == nullptr) {
        std::cout << "The data is not found\n";
        return;
    }

    // If the head node is being deleted
    if (prevNode == nullptr) {
        *head = currNode->next;
    }
    else {
        prevNode->next = currNode->next;
    }

    delete currNode;
}

template <typename N>
void sllDeleteList(SingleList<N> **head){
    SingleList<N>* current = *head;

    while (current != nullptr) {
        SingleList<N>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
    
}

#endif