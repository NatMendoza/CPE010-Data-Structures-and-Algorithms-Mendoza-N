#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "sortingAlgo.h"

const int SIZE = 100;

int main() {
    std::string candidates[5] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    int votes[SIZE];
    int voteCounts[5] = {0};

    // Seed random generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate random votes between 1 and 5
    for (int i = 0; i < SIZE; i++) {
        votes[i] = std::rand() % 5 + 1;
    }

    std::cout << "--- UNSORTED VOTES ARRAY ---\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << votes[i] << " ";
    }
    std::cout << "\n\n";

    // Sort the vote array using Insertion Sort
    insertionSort(votes, SIZE);

    std::cout << "--- SORTED VOTES ARRAY ---\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << votes[i] << " ";
    }
    std::cout << "\n\n";

    // Vote Counting
    for (int i = 0; i < SIZE; i++) {
        voteCounts[votes[i] - 1]++;
    }

    // Finding WInner
    int maxVotes = -1;
    int winnerIndex = 0;

    std::cout << "ELECTION RESULTS: \n";
    for (int i = 0; i < 5; i++) {
        std::cout << "Candidate " << (i + 1) << " (" << candidates[i] << "): " 
                  << voteCounts[i] << " votes\n";
        if (voteCounts[i] > maxVotes) {
            maxVotes = voteCounts[i];
            winnerIndex = i;
        }
    }

    std::cout << "\nWINNER: " << candidates[winnerIndex] 
              << " with " << maxVotes << " votes!\n";

    return 0;
}

