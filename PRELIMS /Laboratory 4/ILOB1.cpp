#include <iostream>

/* GLOBAL DECLARATION */
#define maxCap 10

const size_t arrSize = 10;
int stackArr[maxCap];
int top = 1, newData;

/* PROTOTYPE FUNCTIONS */
void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
void display();

int main() {

    int choice;
    /* MAIN DRIVER VROOM VROOM */
    while(true){
        std::cout << "===================================================================" << std::endl;
        std::cout << "Stack Operations \n" <<  std::endl;
        std::cout << "1.PUSH\n2.POP\n3.TOP\n4.isEmpty\n5.isFull\n6.Display" << std::endl;
        std::cout << "===================================================================" << std::endl;
        std::cin >> choice;

        switch(choice){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: Top(); break;
            case 4: std::cout << "Is stack empty? " << isEmpty() << std::endl; break;
            case 5: std::cout << "Is stack full? " << isFull() << std::endl; break;
            case 6: display(); break;
            default: std::cout << "Unalived Choice." << std::endl;
            break;
        }
    }
}

/* FUNCTION DEFINITION */

bool isEmpty() {
    /* HOW TO VERIFY IF STACK IS EMTPY */
    if(top == -1) return true;
    return false;
}

bool isFull(){
    if(top == maxCap - 1) return true;
    return false;
}

void push(){
    // ERROR CHECKING
    if(isFull()){
        std::cout << "Stack Overflow " << std::endl;
        return;
    }
    // PUSHING STACK 
    std::cout << "\nEnter a new Value: " << std::endl;
    std::cin >> newData;
    // HOW TO INSERT THE DATA IN THE STACK
    stackArr[++top] = newData;
}

void pop(){
    // ERROR CHECKING
    if(isEmpty){
        std::cout << "Stack Underflow" << std::endl;
    }

    // DISPLAY THE VALUE THAT WE ARE GOING TO POP IN POP IN BLOOM
    std::cout << "POPPING: " << stackArr[top] << std::endl;

    // DECREMENT THE TOP VALUE FRPM THE STACK
    top--;
}

void Top(){
    // ERROR CATCHING
    if(isEmpty){
        std::cout << "The Stack is empty" << std::endl;
        return;
    }
    // CHECK TOP VALUE
    std::cout << "Top Element: " << stackArr[top] << std::endl;
}

void display() {
    if (isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }

    std::cout << "Stack elements (TOP TO BOT):" << std::endl;
    for (int j = top; j >= 0; j--) {
        std::cout << stackArr[j] << " ";
    }
    std::cout << std::endl;
}