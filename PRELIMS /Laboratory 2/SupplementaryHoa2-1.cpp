#include <iostream>
#include <string> // For Strings
#include <iomanip> // Table design 

/* Problem 1 : Creating a Class for Fruit and Vegetable*/

/* FRUIT CLASS */
class Fruit {
private:
    std::string name;
    double price;
    int quantity;

public:
    // CONSTRUCTOR
    Fruit(std::string n = " ", double p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    // DESTRUCTOR
    ~Fruit() {
        std::cout << "Fruit Destructor Called: " << name << std::endl;
    }

    // COPY CONSTRUCTOR
    Fruit(const Fruit& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // COPY ASSIGNMENT
    Fruit& operator=(const Fruit& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    double totalSum() const {
        return price * quantity;
    }

    void receipt() const {
        std::cout << std::left
                  << std::setw(15) << "Fruit"
                  << std::setw(15) << name
                  << std::setw(12) << price
                  << std::setw(12) << quantity
                  << std::setw(12) << totalSum()
                  << std::endl;
    }
};

/* VEGETABLE CLASS */
class Vegetable {
private:
    std::string name;
    double price;
    int quantity;

public:
    // CONSTRUCTOR
    Vegetable(std::string n = " ", double p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    // DESTRUCTOR
    ~Vegetable() {
        std::cout << "Vegetable Destructor Called: " << name << std::endl;
    }

    // COPY CONSTRUCTOR
    Vegetable(const Vegetable& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // COPY ASSIGNMENT
    Vegetable& operator=(const Vegetable& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    double totalSum() const {
        return price * quantity;
    }

    void receipt() const {
      std::cout << std::left
                  << std::setw(15) << "Vegetables"
                  << std::setw(15) << name
                  << std::setw(12) << price
                  << std::setw(12) << quantity
                  << std::setw(12) << totalSum()
                  << std::endl;
    }
};

/* Problem 3 : TotalSum FUNCTION */
/* FUNCTION DECLARATION */
double totalSum(Fruit* fruits[], int fruitCount,
                Vegetable* vegetables[], int vegetableCount);

/* THE MAIN PROGRAM */
int main() {

    /* Problem 2: Creating a GroceryList Array */

    Fruit* fruitsTaken[2];
    Vegetable* vegetablesTaken[2];

    fruitsTaken[0] = new Fruit("Apple", 10, 7);
    fruitsTaken[1] = new Fruit("Banana", 10, 8);

    vegetablesTaken[0] = new Vegetable("Broccoli", 60, 12);
    vegetablesTaken[1] = new Vegetable("Lettuce", 50, 10);

    std::cout << "\n================ MEMORY STATUS ================\n";

    std::cout << "Apple Pointer      : " << fruitsTaken[0] << std::endl;

    std::cout << "Banana Pointer     : " << fruitsTaken[1] << std::endl;

    std::cout << "Broccoli Pointer   : " << vegetablesTaken[0] << std::endl;

    std::cout << "Lettuce Pointer    : " << vegetablesTaken[1] << std::endl;

    std::cout << "===============================================\n";

    std::cout << "============================================================\n";
    std::cout << "               JENNA'S GROCERY RECEIPT\n";
    std::cout << "============================================================\n";

    std::cout << std::left
              << std::setw(15) << "Type"
              << std::setw(15) << "Item"
              << std::setw(10) << "Price"
              << std::setw(10) << "Quantity"
              << std::setw(10) << "Total"
              << std::endl;
    std::cout << "------------------------------------------------------------\n";

    std::cout << "Fruits:" << std::endl;
    for (int i = 0; i < 2; i++) {
        fruitsTaken[i]->receipt();
    }

    std::cout << "Vegetables:" << std::endl;
    for (int i = 0; i < 2; i++) {
        vegetablesTaken[i]->receipt();
    }

    std::cout << "\nTotal Amount in Pesos: "
              << totalSum(fruitsTaken, 2, vegetablesTaken, 2)
              << std::endl;

    /* Problem 4 : Deleting Lettuce from Jenna Receipt */

    char answer;

    std::cout << "\nProceed to Delete Lettuce? (Y/N): ";
    std::cin >> answer;

    if (answer == 'Y' || answer == 'y') {

    std::cout << "\n========== POINTER LIST BEFORE DELETION ==========\n";

    std::cout << "Apple Pointer    : " << fruitsTaken[0] << std::endl;
    std::cout << "Banana Pointer   : " << fruitsTaken[1] << std::endl;
    std::cout << "Broccoli Pointer : " << vegetablesTaken[0] << std::endl;
    std::cout << "Lettuce Pointer  : " << vegetablesTaken[1] << std::endl;

    std::cout << "==================================================\n";

    std::cout << "\nDeleting Lettuce...\n";

    delete vegetablesTaken[1];

    vegetablesTaken[1] = nullptr;

    std::cout << "\nMemory successfully deallocated.\n";

    std::cout << "\n========== POINTER LIST AFTER DELETION ==========\n";

    std::cout << "Apple Pointer    : " << fruitsTaken[0] << std::endl;
    std::cout << "Banana Pointer   : " << fruitsTaken[1] << std::endl;
    std::cout << "Broccoli Pointer : " << vegetablesTaken[0] << std::endl;
    std::cout << "Lettuce Pointer  : " << vegetablesTaken[1] << std::endl;

    std::cout << "=================================================\n";

    if (vegetablesTaken[1] == nullptr) {
        std::cout << "\nLettuce successfully deleted.\n";
        std::cout << "Lettuce pointer is now nullptr.\n";
    }
}
    else {
    std::cout << "\nDeletion cancelled.\n";
}

    std::cout << "\nPress Enter to Continue...";
    std::cin.ignore();
    std::cin.get();

    std::cout << "\n============================================================\n";
    std::cout << "              UPDATED GROCERY RECEIPT\n";
    std::cout << "============================================================\n";

    std::cout << "Fruits:" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (fruitsTaken[i] != nullptr) {
            fruitsTaken[i]->receipt();
        }
    }

    std::cout << "\nVegetables:" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (vegetablesTaken[i] != nullptr) {
            vegetablesTaken[i]->receipt();
        }
    }

    std::cout << "\nNew Total Amount in Pesos: "
              << totalSum(fruitsTaken, 2, vegetablesTaken, 2)
              << std::endl;

// Cleaning up memory to prevent memory leak.

    std::cout << "\n========== POINTER LIST BEFORE FINAL CLEANUP ==========\n";

    std::cout << "Apple Pointer    : " << fruitsTaken[0] << std::endl;
    std::cout << "Banana Pointer   : " << fruitsTaken[1] << std::endl;
    std::cout << "Broccoli Pointer : " << vegetablesTaken[0] << std::endl;
    std::cout << "Lettuce Pointer  : " << vegetablesTaken[1] << std::endl;

    std::cout << "=======================================================\n";

    std::cout << "\nCleaning up remaining memory...\n";

// Delete Apple and Banana
    for (int i = 0; i < 2; i++) {
    delete fruitsTaken[i];
    fruitsTaken[i] = nullptr;
}

// Delete Broccoli
    delete vegetablesTaken[0];

    vegetablesTaken[0] = nullptr;

    std::cout << "\nMemory successfully cleaned up.\n";

    std::cout << "\n========== POINTER LIST AFTER FINAL CLEANUP ==========\n";

    std::cout << "Apple Pointer    : " << fruitsTaken[0] << std::endl;
    std::cout << "Banana Pointer   : " << fruitsTaken[1] << std::endl;
    std::cout << "Broccoli Pointer : " << vegetablesTaken[0] << std::endl;
    std::cout << "Lettuce Pointer  : " << vegetablesTaken[1] << std::endl;

    std::cout << "======================================================\n";

    if (fruitsTaken[0] == nullptr &&
        fruitsTaken[1] == nullptr &&
        vegetablesTaken[0] == nullptr &&
        vegetablesTaken[1] == nullptr) {

    std::cout << "\nAll dynamically allocated memory has been deallocated successfully.\n";
    std::cout << "No memory leaks remain.\n";
}

    return 0;
}

/* Problem 3 : TotalSum FUNCTION */
/* FUNCTION DEFINITION */
double totalSum(Fruit* fruits[], int fruitCount,
                Vegetable* vegetables[], int vegetableCount) {

    double total = 0;

    for (int i = 0; i < fruitCount; i++) {
        if (fruits[i] != nullptr) {
            total += fruits[i]->totalSum();
        }
    }

    for (int i = 0; i < vegetableCount; i++) {
        if (vegetables[i] != nullptr) {
            total += vegetables[i]->totalSum();
        }
    }

    return total;
}