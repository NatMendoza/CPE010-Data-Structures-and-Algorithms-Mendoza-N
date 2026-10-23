#include <iostream>
#include "BST.h"


int main() {
    // Root Node
    BinarySearchTree<int> tree(20);


    tree.insert(10);
    tree.insert(5);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    tree.insert(50);


    std::cout<< "The PreOder: ";
    tree.preOrder();
    std::cout << std::endl;


    std::cout<< "The InOrder: ";
    tree.inOrder();
    std::cout << std::endl;


    std::cout<< "The PostOrder: ";
    tree.postOrder();
    std::cout << std::endl;




    return 0;
}

