#include <iostream>

int main() {
    int capOfSection = 1, capOfStudent = 1, capOfGrade = 1, numberSection, exit = 0;

    int studentsnumber, studentsgrade;
    
    std::cout << "Enter a Number of Section: ";
    std::cin >> numberSection;

    if (numberSection < 0) {
        std::cout << "Invalid number of sections!";
    }
    else{
        while(capOfSection <= numberSection){
            std::cout << "Enter a Number Students in Section " << capOfSection << ": ";
            std::cin >> studentsnumber;
            capOfSection++;
        }
        std::cout << std::endl;

        capOfSection = 1;

        Grades:
        capOfGrade = 1;
        capOfStudent++;
        while(capOfGrade != studentsnumber + 1){
            std::cout << "Enter Exam Score of Student Number " << capOfGrade << " in Section " << capOfStudent - 1 << ": ";
            std::cin >> studentsgrade;
            capOfGrade++;
        }
        std::cout << std::endl;

        if(numberSection != capOfStudent-1){
            goto Grades;
        }

        Average:
        capOfSection = 1;
        if(studentsnumber <= 5){
            std::cout << "Average score of students in Section " << capOfSection << ": ";

            capOfSection++;
        }
        else {
            goto Average;
        }
    }
}