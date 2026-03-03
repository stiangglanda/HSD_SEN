#include <iostream>

using namespace std;

int main() {
    int euro = 0;
    const float ATStoEuro = 13.7603;
    cout << "Please enter a number: ";
    cin >> euro;

    cout << euro << "€ sind " << euro * ATStoEuro << " Schilling(ATS)" << endl;
    return 0;
}