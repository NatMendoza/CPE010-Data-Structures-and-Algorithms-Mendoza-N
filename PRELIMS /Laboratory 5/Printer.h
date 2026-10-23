#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <string>
#include "Job.h"
#include "queueArr.h"

class Printer {
private:
    queueArr<Job> jobQueue;

public:
    Printer(int capacity) : jobQueue(capacity) {}

    void addJob(const Job& job) {
        jobQueue.enqueue(job);
        std::cout << "\nJob Added Successfully!\n";
        job.display();
        std::cout << "\n";
    }

    void displayAndRemoveJob() {
        if (jobQueue.Empty()) {
            std::cout << "\nNo jobs available to display or remove.\n";
            return;
        }

        // 1. Display current elements with index positions
        jobQueue.displayQueue();

        // 2. Ask user which index to remove or to exit
        int indexToRemove;
        std::cout << "\nEnter array index position to remove (or -1 to Return/Exit): ";
        std::cin >> indexToRemove;

        // Check for exit choice
        if (indexToRemove == -1) {
            std::cout << "\nReturning to main menu without removing any jobs.\n";
            return;
        }

        // 3. Remove selected index
        if (indexToRemove >= 0 && jobQueue.removeAt(static_cast<size_t>(indexToRemove))) {
            std::cout << "\nSuccessfully removed element at index " << indexToRemove << "!\n";
            
            // 4. Display updated array state
            std::cout << "\n===== Updated Queue State =====\n";
            jobQueue.displayQueue();
        }
    }

    void runProgram() {
        int choice;
        std::string user;
        int id;
        int pages;

        do {
            std::cout << "\n=====================================\n";
            std::cout << "      SHARED PRINTER SIMULATOR\n";
            std::cout << "=====================================\n";
            std::cout << "1. Add Print Job\n";
            std::cout << "2. Display Jobs & Remove Specific Index\n";
            std::cout << "3. Exit\n";
            std::cout << "=====================================\n";
            std::cout << "Enter Choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1: {
                std::cin.ignore();
                std::cout << "\nEnter Username: ";
                getline(std::cin, user);

                std::cout << "Enter Job ID: ";
                std::cin >> id;

                std::cout << "Enter Number of Pages: ";
                std::cin >> pages;

                addJob(Job(user, id, pages));
                break;
            }

            case 2: {
                displayAndRemoveJob();
                break;
            }

            case 3: {
                std::cout << "\nExiting Program...\n";
                break;
            }

            default: {
                std::cout << "\nInvalid Choice!\n";
            }
            }
        } while (choice != 3);
    }
};

#endif