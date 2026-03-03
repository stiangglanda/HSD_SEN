///////////////////////////////////////////////////////////////////////////
// Workfile : Main.cpp
// Author : Leander Kieweg
// Date : 21. 11. 2025
// Description : Test Driver for Prime Module
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Prime.h"

using namespace std;

int main() {
    int input = 0;
    cout << "Eingabe: ";
    cin >> input;

    if (input < 2) {
        cout << "The input number should be at least 2";
        return 1;
    }

    CalcPrimeFactors(input);

    return 0;
}