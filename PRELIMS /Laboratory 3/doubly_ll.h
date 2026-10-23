#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public: T data;
    DoubleList<T>* prev = nullptr;
    DoubleList<T>* next = nullptr;
};

// Creating a Node:
template <typename T>
DoubleList<T> *CreateNewNode(T newData){
    // Dynamically allocate a new memory for the node
    DoubleList<T> *newNode = new DoubleList<T>;
    // Store the data in the node
    newNode->data = newData;
    // Point next and prev to null
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // Return the address of the newly created node
    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T>* currentNode){

    // Temporary Variable to store the last node visisted
    DoubleList<T> *tail;

    // Check if the list is empty
    if(currentNode == nullptr){
        std::cout<<"The list is empty"<<std::endl;
        return;
    }

    std::cout<<"Forward: \n";

    // Move Forward
    while(currentNode != nullptr){
        std::cout << currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }

    // Add a next line
    std::cout<<std::endl;

    // Move Backward

    std::cout<<"Backward: \n";

    while(tail != nullptr){
        std::cout << tail->data << " ";
        tail = tail->prev;
    }
}

// Inserting at the head of the list

template <typename T>
void dllInsertHead(T newData, DoubleList<T> ** currentHead){
    // Creating a new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    // New Node should point to the current head
    newNode->next = *currentHead;

    // Current Head should point back to the newNode
    (*currentHead)->prev = newNode;

    // Update the pointer head
    *currentHead = newNode;
}

template <typename T>

void dllInsertEnd(T newData, DoubleList<T>* currentHead){
    // Createa new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    // Traverse until we reach the last node
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }

    // Connect the last node to the new node
    currentHead->next = newNode;

    // Connect the new node back to the last node
    newNode->prev = currentHead;
}

// GENERAL INSERT
template <typename T>
void dllGeneralInsert(T newData, DoubleList<T>* prevNode){

    // Check if it is the head node (previous node is null)
    if(prevNode == nullptr){
        // If null, print "Previous node cannot be null."
        std::cout<<"Previous value cannot be null"<<std::endl;
        return;
    }
    // Create a new node
    DoubleList<T>* newNode = new DoubleList<T>;

    //4. Store data in the new node
    newNode->data = newData; // Backward
    newNode->next = prevNode->next; // Forward

    //5. Point new node to the node previous node was pointing to
    newNode->prev = prevNode; // Backward
    newNode->next = prevNode->next; // Forward

    // 6. If the node after newNode exists, update its 'prev' pointer to newNode
    prevNode->next = newNode; // Forward
    if (newNode->next != nullptr) { // Backward
        newNode->next->prev = newNode;
    }

}

// DELETE A NODE
template <typename T>
void dllDeleteNode(T findData, DoubleList<T>** head) { 

    // If list is empty, nothing to delete
    if (*head == nullptr) return;

    DoubleList<T>* currentNode = *head;

    // Search for the target node
    while (currentNode != nullptr && currentNode->data != findData) {
        currentNode = currentNode->next;
    }

    // Data not found
    if (currentNode == nullptr) {
        std::cout << "The data was not found\n" << std::endl;
        return;
    }

    // If data was found then Update the NEXT pointer of the PREVIOUS node
    if (currentNode == *head) {
        // If deleting the head node, move the head pointer forward
        *head = currentNode->next;
    } else {
        // Otherwise, skip over currentNode using next pointer
        currentNode->prev->next = currentNode->next;
    }

    // Update the PREV pointer of the NEXT node
    if (currentNode->next != nullptr) {
        currentNode->next->prev = currentNode->prev;
    }

    // Free memory
    delete currentNode;
}

#endif