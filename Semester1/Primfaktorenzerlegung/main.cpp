#include <iostream>
using namespace std;

int main() {
    int input=0;
    int currentPrimeNumber=2;

    cout << "Eingabe: ";
    cin >> input;

    if (input<2) {
        cout << "The input number should be at least 2";
        return 0;
    }

    int primeDivisionResult=input;

    cout << "Ausgabe: ";

    while (primeDivisionResult>1)
    {
        if (primeDivisionResult%currentPrimeNumber==0)
        {
            primeDivisionResult=primeDivisionResult/currentPrimeNumber;
            cout << currentPrimeNumber;
            if (primeDivisionResult>1) {
                cout << ", ";
            }
        }
        else {
            currentPrimeNumber++;
        }
    }

    return 0;
}