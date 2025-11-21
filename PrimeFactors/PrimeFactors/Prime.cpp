#include "Prime.h"
#include <iostream>

using namespace std;

//Helper function for the module therefore static
static bool Divides(size_t const divisor, size_t const dividend) {
    if (divisor == 0) {
        return false;
    }
    return dividend % divisor == 0;
}

//Helper function for the module therefore static
static void PrintPrimeFactor(size_t const factor, bool const comma) {
    if (comma) {
        cout << ", ";
    }
    cout << factor;
}

void CalcPrimeFactors(size_t const number) {
    if (number < 2) {
        cout << "The input number should be at least 2";
        return;
    }

    size_t currentPrimeNumber = 2;
    size_t primeDivisionResult = number;
    bool isFirstFactor = true;//for the comma

    cout << "Ausgabe: ";

    while (primeDivisionResult > 1)
    {
        if(Divides(currentPrimeNumber, primeDivisionResult))
        {
            primeDivisionResult = primeDivisionResult / currentPrimeNumber;
            PrintPrimeFactor(currentPrimeNumber, !isFirstFactor);
            isFirstFactor = false;
        }
        else {
            currentPrimeNumber++;
        }
    }
}