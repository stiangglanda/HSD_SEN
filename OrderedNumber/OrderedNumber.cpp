///////////////////////////////////////////////////////////////////////////
// Workfile : OrderedNumber.cpp
// Author : Leander Kieweg
// Date : 9. 11. 2025
// Description : Checks if a number is Ordered
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main() {
    int inputNumber = 0;
    int currentDigit = 0;

    cout << "Input: " << endl;
    cin >> inputNumber;

    if(inputNumber < 0) {
        cout << "Invalid Input" << endl;
        return 1;
    }
    else if (inputNumber<10) {
        cout << "ordered" << endl;
        return 0;
    }

    int neighborDigit=inputNumber % 10;
    inputNumber /= 10;

    while(inputNumber > 0) {
        currentDigit=inputNumber % 10;//Digit extraction
        inputNumber /= 10;

        if(abs(currentDigit-neighborDigit)>1) {//check if dignits are neighbors
            cout << "not ordered" << endl;
            return 0;
        }
        neighborDigit=currentDigit;
    }
    cout << "ordered" << endl;
    return 0;
}