#include <iostream>
#include <queue>

void display(std::queue<char> copyQ);

int main() {

    // Create an object
    std::queue<char> myQ;

    // Use Enqueue operation
    myQ.push('S');
    myQ.push('H');
    myQ.push('I');
    myQ.push('N');
    myQ.push('J');
    myQ.push('I');

    // Print the front and the back of the queue
    std::cout << "Current front of the queue is: " << myQ.front() << std::endl;
    std::cout << "Current back of the queue is: " << myQ.back() << std::endl;
    std::cout << std::endl;
    // Print the ENTIRE queue
    display(myQ); 

    // Use Dequeue operation
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();

    std::cout << "Is the queue empty? " << myQ.empty() << std::endl;

    return 0;
}

void display(std::queue<char> copyQ){

    // Create a copy of the queue
    std::queue<char> tempQ(copyQ);
    // Loop until Empty
    while (!tempQ.empty()) {
        std::cout << "Current front of the queue is: " << tempQ.front() << std::endl;
        tempQ.pop();
    } 
    std::cout << std::endl;
}