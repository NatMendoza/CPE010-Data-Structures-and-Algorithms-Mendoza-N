#include "node.h"
#include <iostream>

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

//================ ARRAY ========================================

template<typename T>
void linearSearch(int size,T item,T array[]){
    for (int i = 0; i < size;i++){
        if(array[i] == item){
            std::cout << "Data Found at index " << i << "\n";
            return;
        }
    }
    std::cout << "Data not found\n";
}

template<typename T>
void binarySearchArr(T data[],int arrSize,T dataFind){
    int low = 0;
    int high = arrSize - 1;
    int middle;

    while (low <= high){
        middle = (int)((low+high)/2);
        if (dataFind == data[middle]){
            std::cout << "The data was found\n";
            return;
        }
        else if (dataFind < data[middle]){
            high = middle - 1;
        }
        else {
            low = middle + 1;
        }
    }

    std::cout << "The data was not found\n";
}

//===================================================================

//=============================== LINKED LIST ================================
template<typename T>
void linearSearchLL(Node<T> *headNode, T dataToBeFound){
    while (headNode != nullptr){
        if (headNode->data == dataToBeFound){
            std::cout << "Found Data inside the node\n";
            return;
        }
        headNode = headNode->next;
    }
    std::cout << "Data not found in nodes given\n";
}

template<typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* end){
    Node<T>* slow = start;
    Node<T>* fast = start;

    while (fast != end && fast->next!= end){
        slow = slow->next;

        fast = fast->next->next;
    }

    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind) {
    Node<T>* last = nullptr;
    
    while (start != last) {
        Node<T>* middle = getMiddle(start, last);

        if (middle->data == dataFind) {
            std::cout << "Data found\n";
            return;
        }
        else if (middle->data > dataFind) {
            last = middle;
        }
        else {
            start = middle->next; 
        }
    }

    std::cout << "Data not found\n";
}

#endif


