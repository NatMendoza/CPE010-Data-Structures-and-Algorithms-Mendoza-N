#include <iostream>
#include "SupplementarySearchingAlgorithm.h"

int main() {
    // PROBLEM 1
  
    std::cout << "PROBLEM 1:\n";
    int list1[10] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int key1 = 18;

    // Array Approach
    linearSearchArray(list1, 10, key1);
    // Linked List Approach
    Node<int>* head = newNode(15);
    Node<int>* curr = head;
    int remainingValues[9] = {18, 2, 19, 18, 0, 8, 14, 19, 14};
    for (int val : remainingValues) {
        curr->next = newNode(val);
        curr = curr->next;
    }
    linearSearchLinkedList(head, key1);
    deleteNodes(&head);
    std::cout << "\n";

    // PROBLEM 2
    std::cout << "PROBLEM 2:\n";
    int occurrences = countOccurrences(list1, 10, key1);
    std::cout << "Key '" << key1 << "' appears " << occurrences << " times in the list.\n\n";

    // PROBLEM 3

    std::cout << "PROBLEM 3:\n";
    int list2[10] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int key2 = 8;
    std::cout << "Iterative Binary Search for Key 8: ";
    binarySearchIterative(list2, 10, key2);
    std::cout << "\n";

    // PROBLEM 4
    std::cout << "PROBLEM 4:\n";
    std::cout << "Recursive Binary Search for Key 8: ";
    binarySearchRecursive(list2, 0, 9, key2);
    std::cout << "\n";

    return 0;
}

