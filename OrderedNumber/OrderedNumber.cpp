///////////////////////////////////////////////////////////////////////////
// Workfile : OrderedNumber.cpp
// Author : Leander Kieweg
// Date : 9. 11. 2025
// Description : Some functions to merge different containers.
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main() {
    int inputNumber = 0;
    int currentDigit=0;
    int neighborDigit=0;
    //vector<unsigned int> resistanceDigitVec = {};

    cout << "Eingabe: " << endl;
    cin >> inputNumber;

    if(inputNumber < 0) {
        cout << "Eingabe: " << endl;
        return 0;
    }
    else if (inputNumber==0) {
        cout << "ordered" << endl;
        return 0;
    }

    neighborDigit=inputNumber % 10;
    inputNumber /= 10;

    while(inputNumber > 0) {
        currentDigit=inputNumber % 10; //insert so you dont need invert
        inputNumber /= 10;

        if(abs(currentDigit-neighborDigit)!=1) {
            cout << "not ordered" << endl;
            return 0;
        }
        neighborDigit=currentDigit;
    }
    cout << "ordered" << endl;
    return 0;
}