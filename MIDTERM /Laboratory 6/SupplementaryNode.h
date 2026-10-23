#ifndef SUPPLEMENTARYNODE_H
#define SUPPLEMENTARYNODE_H

template<typename T>
class Node {
public:
    T data;
    Node* next;
};

template<typename T>
Node<T>* newNode(T newData) {
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

template<typename T>
void deleteNodes(Node<T>** head) {
    Node<T>* current = *head;
    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    *head = nullptr;
}

#endif