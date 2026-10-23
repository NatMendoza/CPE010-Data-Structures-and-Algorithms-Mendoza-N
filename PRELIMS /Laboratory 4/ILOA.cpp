#include <iostream>
#include <stack>

int main () {
    std::stack<int>stack1;
    std::stack<int>stack2;

    std::cout << "Testing the Stack STL" << std::endl;
    std::cout<< "Is the stack empty? " << stack1.empty();

    /* PUSH */
    std::cout << "\nTesting STACK PUSHING" << std::endl;
    stack1.push(10);    
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;  
    stack1.push(9);
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;  
    stack1.push(8);
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;  
    stack1.push(7);
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;  

    /* POP */
    std::cout << "\nTesting STACK POPPING" << std::endl;
    stack1.pop();
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;  

    std::cout <<  "Is the stack empty? " << stack1.empty() << std::endl;

    std::cout << "The size of the stack is: " << stack1.size() << std::endl;

    /* STACK EMPLACE*/
    std::cout << "\nTesting STACK EMPLACE" << std::endl;
    std::cout << "Stack Emplace: " << stack1.emplace(9) << std::endl;

    /* STACK SWAP */
    std::cout << "\nTesting STACK SWAPPING" << std::endl;
    stack2.push(10);    
    std::cout << "The top of the stack is: " << stack2.top() << std::endl;  
    stack2.push(9);
    std::cout << "The top of the stack is: " << stack2.top() << std::endl;  
    stack2.push(8);
    std::cout << "The top of the stack is: " << stack2.top() << std::endl;  
    stack2.push(7);
    std::cout << "The top of the stack is: " << stack2.top() << std::endl; 

    stack1.swap(stack2);
    
    std::cout << "Stack Swapping: " << stack1.top() << std::endl;
    std::cout << "The top of the stack 1 is: " << stack1.top() << std::endl; 
    std::cout << "The top of the stack 2 is: " << stack2.top() << std::endl; 
}

