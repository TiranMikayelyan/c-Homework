#include <iostream>

int divide(int a, int b) {
    if (b == 0)
        throw "Can't divide by zero";
    return a / b;
}

int main() {
    int a, b;
    std::cout << "a=";
    std::cin >> a;
    std::cout << "b=";
    std::cin >> b;
    try {
        std::cout << divide(a, b) << std::endl;
    }
    catch (const char* error) {
        std::cout << "Error: " << error << std::endl;
    }

    return 0;
}
