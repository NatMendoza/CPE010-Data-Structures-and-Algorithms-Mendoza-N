#include <iostream>
#include "singly_ll.h"

int main(){
    // creating a node stored in the stack
    SingleList<char>* head = nullptr;
    SingleList<char>* second = nullptr;
    SingleList<char>* third = nullptr;
    SingleList<char>* fourth = nullptr;

    // allocates memory in the heap
    head = new SingleList<char>;
    second = new SingleList<char>;
    third = new SingleList<char>;
    fourth = new SingleList<char>;
    
    // storing a value inside the node
    head->data = 'J';
    second->data = 'P';
    third->data = 'C';
    fourth->data = 'L';

    // linking the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    std::cout << head->next << std::endl;
    std::cout << second->next << std::endl;
    std::cout << third->next << std::endl;
    std::cout << fourth->next << std::endl;

    std::cout << "Testing of traversal\n";
    ListTraversal(head);

    std::cout << "Testing of sllinsertHead\n";
    sllinsertHead('Q', &head); 
    ListTraversal(head);

    std::cout << "Testing of sllGeneralInsert\n";
    sllGeneralInsert('X', head->next->next); 
    ListTraversal(head);

    std::cout << "Testing of sllinsertEnd\n";
    sllinsertEnd('U', &head);
    ListTraversal(head);

    std::cout << "Testing of deleting the node\n";
    sllDeleteNode('U', &head);
    ListTraversal(head);

    std::cout << "Deleting all nodes\n";
    sllDeleteList(&head);
    ListTraversal(head);    

    return 0;
}
