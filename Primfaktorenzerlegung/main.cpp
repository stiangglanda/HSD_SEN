#include <iostream>

int main() {
    int input=0;

    std::cout << "Eingabe: ";
    std::cin >> input;

    if (input<2) {
        std::cout << "The input number should be at least 2";
        return 0;
    }


    int primeDivisionResult=input;
    int currentPrimeNumber=2;

    std::cout << "Ausgabe: ";

    while (primeDivisionResult>1)
    {
        if (primeDivisionResult%currentPrimeNumber==0)
        {
            primeDivisionResult=primeDivisionResult/currentPrimeNumber;
            std::cout << currentPrimeNumber;
            if (primeDivisionResult>1) {
                std::cout << ", ";
            }
        }
        else {
            currentPrimeNumber++;
        }
    }

    return 0;
}