///////////////////////////////////////////////////////////////////////////
// Workfile : DualConverter.cpp
// Author : Leander Kieweg
// Date : 11. 11. 2025
// Description : Converts numbers from Decimal to binary
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

unsigned int Dual2Dec(bool b7, bool b6, bool b5, bool b4, bool b3, bool b2, bool b1, bool b0)
{
    return b7 * 128 + b6 * 64 + b5 * 32 + b4 * 16 +
           b3 * 8 + b2 * 4 + b1 * 2 + b0 * 1;
}

int Dual2Dec(size_t dualValue)
{
    int decimalValue = 0;
    int position = 0;
    while (dualValue > 0) {
        int lastDigit = dualValue % 10;
        if (lastDigit > 1) {
            return 0; // Fehlerbehandlung bei nicht dualzahl
        }
        decimalValue += lastDigit * (1 << position); // 2^position
        dualValue /= 10;
        position++;
    }
    return decimalValue;
}

int main() 
{
    size_t DualNumber = 11111111;

    cout << "Output: size_t variant: " << Dual2Dec(DualNumber)
    << " bool variant: " << Dual2Dec(1,1,1,1,1,1,1,1) << endl;

    return 0;
}