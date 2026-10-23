#ifndef JOB_H
#define JOB_H

#include <string>
#include <iostream>

class Job {
    private:
        std::string Username;
        int jobID;
        int paperCount;
    
    public:
        // Default Constructor
        Job(){
            Username = "";
            jobID = 0;
            paperCount = 0;
        }

        // Constructor
        Job(std::string user, int id, int count){
            Username = user;
            jobID = id;
            paperCount = count;
        }

        // Getters
        int getJobID() const {
            return jobID;
        }

        std::string getUsername() const {
            return Username;
        }

        int getPaperCount() const {
            return paperCount;
        }

        // Display function
        void display() const {
            std::cout << "Job ID: " << jobID 
                      << ", Username: " << Username 
                      << ", Paper Count: " << paperCount;
        }

        // Stream insertion operator overload
        friend std::ostream& operator<<(std::ostream& os, const Job& job) {
            os << "Job ID: " << job.jobID 
               << ", Username: " << job.Username 
               << ", Paper Count: " << job.paperCount;
            return os;
        }
};

#endif // JOB_H


