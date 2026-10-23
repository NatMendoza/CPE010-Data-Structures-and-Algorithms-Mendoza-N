#include <iostream>
#include <cmath>
#include <string>

// Task 1 Function Declaration
void numSwap();

// Task 2 Function Declaration
double kelvinToFahrenheit(double kelvin);

// Task 3 Function Declaration
void calculateDistance();
double distanceCalculator(double x1, double x2, double y1, double y2);

// TASK 4 Class

class Triangle {
private:
    double sideA, sideB, sideC;
    double angleA, angleB, angleC;
    double totalAngle;

public:
    Triangle(double sA, double sB, double sC,
             double A, double B, double C);

    void setTriangle(double sA, double sB, double sC,
                     double A, double B, double C);

    bool validateTriangle();

    double getArea();

    double getPerimeter();

    std::string triangleType();
};

// MAIN PROGRAM
int main() {

    double kelvin;

    Triangle tri(5, 6, 7, 40, 50, 90);

    std::cout << "Task #1 Swapping two numbers in different variables." << std::endl;
    numSwap();

    std::cout << "\nTask #2 Function converting temperature in Kelvin to Fahrenheit" << std::endl;
    std::cout << "Enter Temperature you want to convert in Kelvin: ";
    std::cin >> kelvin;

    std::cout << "\nTemperature converted to Fahrenheit: "
              << kelvinToFahrenheit(kelvin) << " Fahrenheit" << std::endl;

    std::cout << "\nTask #3 Calculating Distance Between Two Points" << std::endl;
    calculateDistance();

    std::cout << "\nTask #4 Modifying Triangle Class and getting Area, Perimeter, Triangle Type Determiner" << std::endl;

    if (tri.validateTriangle()) {
        std::cout << "The triangle is valid.\n";
        std::cout << "Perimeter : " << tri.getPerimeter() << std::endl;
        std::cout << "Area      : " << tri.getArea() << std::endl;
        std::cout << "Type      : " << tri.triangleType() << std::endl;
    }
    else {  
        std::cout << "The triangle is NOT valid.\n";
    }
    
    return 0;
}

// FUNCTION DEFINITIONS

// Task 1
void numSwap() {

    int a, b, temp;

    std::cout << "Input Values for A and B\n";
    std::cout << "A = ";
    std::cin >> a;
    std::cout << "B = ";
    std::cin >> b;

    std::cout << "\nCurrent Values of A and B Before Swapping\n";
    std::cout << "A = " << a << std::endl;
    std::cout << "B = " << b << std::endl;

    temp = a;
    a = b;
    b = temp;

    std::cout << "\nValues after swapped" << std::endl;
    std::cout << "A = " << a << std::endl;
    std::cout << "B = " << b << std::endl;
}

// Task 2
double kelvinToFahrenheit(double kelvin) {

    return (kelvin - 273.15) * 9 / 5 + 32;

}

// Task 3
void calculateDistance() {

    double x1, x2, y1, y2;

    std::cout << "Enter x1: ";
    std::cin >> x1;

    std::cout << "Enter y1: ";
    std::cin >> y1;

    std::cout << "Enter x2: ";
    std::cin >> x2;

    std::cout << "Enter y2: ";
    std::cin >> y2;

    std::cout << "\nDistance Calculated from your Inputs:" << std::endl;
    std::cout << "X1 : " << x1 << std::endl;
    std::cout << "Y1 : " << y1 << std::endl;
    std::cout << "X2 : " << x2 << std::endl;
    std::cout << "Y2 : " << y2 << std::endl;

    std::cout << "Distance is = " << distanceCalculator(x1, x2, y1, y2) << std::endl;
}

double distanceCalculator(double x1, double x2, double y1, double y2) {

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

}

// Task 4 Function Definitions

// Constructor
Triangle::Triangle(double sA, double sB, double sC,
                   double A, double B, double C)
{
    sideA = sA;
    sideB = sB;
    sideC = sC;

    angleA = A;
    angleB = B;
    angleC = C;

    totalAngle = A + B + C;
}

// Setter
void Triangle::setTriangle(double sA, double sB, double sC,
                           double A, double B, double C)
{
    sideA = sA;
    sideB = sB;
    sideC = sC;

    angleA = A;
    angleB = B;
    angleC = C;

    totalAngle = A + B + C;
}

// Validator
bool Triangle::validateTriangle()
{
    return totalAngle == 180;
}

// Perimeter
double Triangle::getPerimeter()
{
    return sideA + sideB + sideC;
}

// Area
double Triangle::getArea()
{
    double s = getPerimeter() / 2;

    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

// Triangle Type Determiner
std::string Triangle::triangleType()
{
    if (angleA < 90 && angleB < 90 && angleC < 90)
        return "Acute-Angled";

    else if (angleA > 90 || angleB > 90 || angleC > 90)
        return "Obtuse-Angled";

    else
        return "Others";
}