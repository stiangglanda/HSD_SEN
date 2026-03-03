#include <iostream>

using namespace std;

void MyAddFunction(const int inVal, int &outval);

int main() {
    int result=0;
    int input=1;
    while (input!=0) {
        cout << endl << "Wert eingeben (o beendet): " << endl;
        cin >> input;
        if (input!=0) {
            MyAddFunction(input,result);
            cout << "Bisherige Summe: " << result << endl;
        }
    }

    return 0;
}

void MyAddFunction(const int inVal, int &outval) {
    static int lastSum=0;

    lastSum += inVal;
    outval = lastSum;
}