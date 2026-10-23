#include <iostream>
#include "queueLL.h"

int main() {

    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    std::cout << "===== TESTING ENQUEUE =====\n";

    enqueue('E', &front, &back);
    enqueue('Y', &front, &back);
    enqueue('D', &front, &back);
    enqueue('I', &front, &back);
    enqueue('S', &front, &back);

    displayALL(&front, &back);

    std::cout << "Front: " << front->data << std::endl;
    std::cout << "Back : " << back->data << std::endl;

    std::cout << "\nIs Empty? "
              << (isEmpty(&front, &back) ? "Yes" : "No")
              << std::endl;

    std::cout << "\n===== TESTING DEQUEUE =====\n";

    dequeue(&front, &back);
    displayALL(&front, &back);

    dequeue(&front, &back);
    displayALL(&front, &back);

    dequeue(&front, &back);
    displayALL(&front, &back);

    dequeue(&front, &back);
    displayALL(&front, &back);

    dequeue(&front, &back);
    displayALL(&front, &back);

    std::cout << "\nIs Empty? "
              << (isEmpty(&front, &back) ? "Yes" : "No")
              << std::endl;

    // Test dequeue on empty queue
    dequeue(&front, &back);

    return 0;
}



