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

int Dual2Dec(bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool h)
{
    return a * 128 + b * 64 + c * 32 + d * 16 + e * 8 + f * 4 + g * 2 + h * 1;
}

int Dual2Dec(size_t dualValue)
{
    int decimalValue = 0;
    int position = 0;
    while (dualValue > 0) {
        int lastDigit = dualValue % 10;
        decimalValue += lastDigit * (1 << position); // 2^position
        dualValue /= 10;
        position++;
    }
    return decimalValue;
}

int main() 
{
    size_t DualNumber = 10010010;

    cout << "Output: size_t variant: " << Dual2Dec(DualNumber) << " bool variant: " << Dual2Dec(1,0,0,1,0,0,1,0) << endl;

    return 0;
}