#include <iostream>
#include <string.h>

class Student{
    private:
        std::string studentName;
        int studentAge;

    public:
    /* CONSTRUCTOR */
    Student(std::string newName = "Eydis", int newAge = 18){

        studentName = std::move(newName);
        studentAge = newAge;
        std::cout << "CALLED CONSTRUCTOR" << std::endl;

    };
    /* DECONSTRUCTOR */
    ~Student(){

        std::cout << "CALLED DESTRUCTION" << std::endl;

    }

    /*  COPY CONSTRUCTOR */
    Student(const Student &copyStudent){

        std::cout << "CALLED COPY CONSTRUCTOR" << std::endl;
        studentName = copyStudent.studentName;
        studentAge =  copyStudent.studentAge;
    }

    /* DISPLAY ATTRIBUTES */
    void printDetails(){
        std::cout << this->studentName << " " << this->studentAge << std::endl;
    }

};

int main() {

    const size_t j = 5;

    Student studentList[j] = {};
    std::string nameList[j] = {"Asuna", "Fang Yuan", "Sunless", "Nephis", "Klein"};
    int ageList[j] = {20, 37, 25, 19, 16};

    /* LOOP A */
    for(int i = 0; i < j; i++) {
        Student *ptr = new Student(nameList[i], ageList[i]);
        studentList[i] = *ptr;

        /* MODIFICATION */
        delete ptr;   
        ptr = nullptr;
    }

    /* LOOP B */
    for(int i = 0; i < j; i++) { // LOOP B
        studentList[i].printDetails(); 
    }

    return 0;
}