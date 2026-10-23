#include <iostream>


// FUNCTION DECLARATIONS


// ILO A DECLARATION
int sumOfTwoNum(int fNum, int sNum); // Number 1


bool isGreater(int a, int b); // Number 2


bool displayLogicalOperations(bool c, bool d); // Number 3


// CLASS
class Triangle {
    private:
        double totalAngle, angleA, angleB, angleC;
    public:
        Triangle(double A, double B, double C);
        void setAngles(double A, double B, double C);
        const bool validateTriangle();
};


// MAIN PROGRAM


int main () {


    // ILO A #1


    std::cout << "The sum of all numbers is : " << sumOfTwoNum(10,22) << std::endl;


    // ILO A #2
    int x = 500;
    int y = 400;


   if (isGreater(x, y)) {
        std::cout << "x is greater than y" << std::endl;
    } else {
        std::cout << "x is not greater than y" << std::endl;
    }


    // ILO A #3


    bool success = displayLogicalOperations(true, false);
   
    std::cout << "Function execution status: " << std::boolalpha << success << std::endl;


    // ILO B
    Triangle setl(40,50,110);
    if(setl.validateTriangle()){
        std::cout << "The shape is a valid Triangle \n.";
    }
    else{
        std::cout << "The shape is NOT a valid Triangle \n.";
    }


    return 0;
}


// FUNCTIONS


// ILO A #1
int sumOfTwoNum(int fNum, int sNum){


    int sum = fNum + sNum;
    return sum;
}
 // ILO A #2
bool isGreater(int a, int b){
    return a > b;
}


// ILO A #3
bool displayLogicalOperations(bool c, bool d) {
    // std::boolalpha formats outputs as "true" or "false" instead of "1" or "0"
    std::cout << std::boolalpha;
   
    std::cout << "Logical Operations Table " << std::endl;
    std::cout << "Inputs: A = " << c << ", B = " << d << std::endl;
   
    // 1. NOT
    std::cout << "NOT A      : " << (!c) << std::endl;
    std::cout << "NOT B      : " << (!d) << std::endl;
   
    // 2. AND
    std::cout << "LOGICAL AND : " << (c && d) << std::endl;
   
    // 3. OR
    std::cout << "LOGICAL OR : " << (c || d) << std::endl;
   
    // 4. XOR
    std::cout << "LOGICAL XOR : " << (c ^ d) << std::endl;


    // 5. NAND
    std::cout << "LOGICAL NAND: " << !(c && d) << std::endl;


    // 6. NOR
    std::cout << "LOGICAL NOR: " << !(c || d) << std::endl;


    // 7. XNOR
    std::cout << "LOGICAL XNOR: " << !(c ^ d) << std::endl;
   
    return true;
}


// ILO B
Triangle::Triangle(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}


void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
}


const bool Triangle::validateTriangle(){
    return (totalAngle <= 180);
}

