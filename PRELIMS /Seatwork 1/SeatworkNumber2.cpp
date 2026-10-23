#include <iostream>
#include <string>
using namespace std;

int main() {
    string item1, item2, item3;
    double itemcost1, itemcost2, itemcost3;
    double total, payment, change;

    cout << "===== Cashiering System =====\n";

    cout << "Enter 1st Item: ";
    cin >> item1;

    cout << "Enter price of Item 1: ";
    cin >> itemcost1;

    cout << "Enter 2nd Item: ";
    cin >> item2;

    cout << "Enter price of Item 2: ";
    cin >> itemcost2;

    cout << "Enter 3rd Item: ";
    cin >> item3;

    cout << "Enter price of Item 3: ";
    cin >> itemcost3;

    total = itemcost1 + itemcost2 + itemcost3;

    cout << "\nTotal: " << total << endl;

    cout << "Enter payment: ";
    cin >> payment;

    change = payment - total;

    cout << "\n----- Receipt -----\n";
    cout << "Item 1: " << item1 << " P" << itemcost1 << endl;
    cout << "Item 2: " << item2 << " P" << itemcost2 << endl;
    cout << "Item 3: " << item3 << " P" << itemcost3 << endl;
    cout << "Total: " << total << endl;
    cout << "Payment: " << payment << endl;
    cout << "Change: " << change << endl;

    return 0;
}
