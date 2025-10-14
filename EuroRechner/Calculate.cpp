#include <iostream>

int main() {
    int euro = 0;
    std::cout << "Please enter a number: ";
    std::cin >> euro;

    std::cout << euro << " € sind " << euro * 14 << " in Schilling" << std::endl;
    return 0;
}