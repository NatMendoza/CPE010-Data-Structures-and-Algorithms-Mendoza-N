#include <iostream>
#include <thread>


void print(int n, const std::string &str) {
    std::cout << "Printing integer: "<< n <<std::endl;
    std::cout<<" Printing string: " << str << std::endl;
}


int main(){

    std::thread t1(print, 10, "T.I.P.");
    t1.join();

    return 0;
}
