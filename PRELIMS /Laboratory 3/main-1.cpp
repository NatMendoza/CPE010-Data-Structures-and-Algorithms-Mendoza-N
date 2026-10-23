#include <iostream>
#include "doubly_ll.h"

int main(){
    // Create a List 'C P E'
    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');

    head->next = second;
    second->prev = head;
    
    second->next = third;
    third->prev = second;

    //Traversal
    std::cout<< "Testing the Double Linked List Traversal: "<<std::endl;
    dllTraverse(head);

    //Testing the insert at the head
    std::cout << "\nTesting the insertion at the head node" << std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    //Testing the insert at the end
    std::cout << "\nTesting the insertion at the end" << std::endl;
    dllInsertEnd('0', head);
    dllTraverse(head);
    
    //Testing General Insert
    std::cout << "\nTesting General Inseration" << std::endl;
    dllGeneralInsert('Z', head);
    dllTraverse(head);

    // Testing Node Deletion
    std::cout << "\nTesting Node Deletion" << std::endl;
    dllDeleteNode('X', &head);
    dllTraverse(head);
}