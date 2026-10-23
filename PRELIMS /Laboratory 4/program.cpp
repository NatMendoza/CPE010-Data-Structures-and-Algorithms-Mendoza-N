#include <iostream>
#include <string>
#include "stackList.h"

int main() {

    std::string expression;
    char choice;

    std::cout << "===== BALANCED SYMBOL CHECKER =====\n";

    do {
        std::cout << "\nEnter an expression: ";
        std::getline(std::cin, expression);

        if (isBalanced(expression))
            std::cout << "Result: Expression is Balanced. Therefore, if and only if, it is Valid!!\n";
        else
            std::cout << "Result: Expression is Unbalanced. Therefore, if and only if, it is Invalid!!\n";

        std::cout << "\nWould you like to test another expression? (Y/N): ";
        std::cin >> choice;
        std::cin.ignore(); // Clears the newline character

    } while (choice == 'Y' || choice == 'y');

    std::cout << "\nProgram Ended! Adios\n";

    return 0;
}