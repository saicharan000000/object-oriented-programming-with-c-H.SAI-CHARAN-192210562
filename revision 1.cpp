#include <iostream>

int main() {
    int integerNumber;
    float floatNumber;

    std::cout << "Enter an integer number: ";
    std::cin >> integerNumber;

    std::cout << "Enter a float number: ";
    std::cin >> floatNumber;

    if (integerNumber == 0) {
        std::cout << "Error: Division by zero is not allowed." << std::endl;
    } else {
        float result = floatNumber / static_cast<float>(integerNumber);
        std::cout << "Result of float divided by integer: " << result << std::endl;
    }

    return 0;
}


