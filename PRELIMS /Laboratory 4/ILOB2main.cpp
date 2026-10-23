#include <iostream>
#include "stackList.h"

int main() {
    
    std::cout << "--- PUSHING 'C' 'P' 'E' ONTO THE STACK ---\n";

    //PUSHING
    push('C');
    push('P');
    push('E');

    //DISPLAY THE CURRENT TOP

    Top<char>; /* TOP ELEMENT SHOULD BE 'E' */
    displayALL<char>();
    std::cout << "\n --- POPPIING ALL ELEMENT ---\n";

    while(!isEmpty<char>()) {
        std::cout<<"Popped: "<< pop<char>() <<std::endl;
    }

    std::cout << "\n --- TESTING THE UNDERFLOW CONDITION --- \n";
    pop<char>(); /* UNDERFLOW CONDITION */

    return 0;
}