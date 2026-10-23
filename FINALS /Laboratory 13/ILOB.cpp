#include <iostream>
#include <string>
#include <vector>
#include <thread>


void print(int n, const std::string &str) {
    std::string msg = std::to_string(n) + " : " + str;
    std::cout << msg << std::endl;
}


int main() {
    std::vector<std::string> s = {
        "T.I.P.",
        "Competent",
        "Computer",
        "Engineers"
    };

    
    std::vector<std::thread> threads;


    for (int i = 0; i < s.size(); i++) {
        threads.push_back(std::thread(print, i, s[i]));
    }


    for (auto &th : threads) {
        th.join();
    }

    return 0;
}
