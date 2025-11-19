#include "Prime.h"
#include <iostream>

using namespace std;

bool Divides(size_t const divisor, size_t const dividend) {
    return divisor % dividend == 0;
}

void PrintPrimeFactor(size_t const factor, bool const comma) {
    cout << factor;
    if (comma) {
        cout << ", ";
    }
}

void CalcPrimeFactors(size_t const number) {
    int currentPrimeNumber = 2;
    int primeDivisionResult = number;

    cout << "Ausgabe: ";

    while (primeDivisionResult > 1)
    {
        if(Divides(primeDivisionResult, currentPrimeNumber))
        {
            primeDivisionResult = primeDivisionResult / currentPrimeNumber;
            PrintPrimeFactor(currentPrimeNumber, primeDivisionResult > 1);
        }
        else {
            currentPrimeNumber++;
        }
    }
}