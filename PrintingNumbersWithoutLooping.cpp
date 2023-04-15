#include <iostream>

int main() {
    int number, exit = 0;

    std::cout << "Enter an Number: ";
    std::cin >> number;

    namias:
    if (number < 0) {
        std::cout << "Invalid number!";
    }
    else if (number != exit){
        exit++;
        std::cout << exit << " ";
        goto namias;
    }
}