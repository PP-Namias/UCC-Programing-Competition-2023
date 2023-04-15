#include <iostream>

int main() {
    int number;

    std::cout << "Enter an Number: ";
    std::cin >> number;

    (number % 2 == 0) ? std::cout << number << " is even!": std::cout << number << " is odd!";
}