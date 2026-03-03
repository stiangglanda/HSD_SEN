#include <iostream>

// Funktion zur Berechnung der Ziffernsumme
// in: Zahl
// out: Ziffernsumme

// 1234 = 10

using namespace std;

//funktionsprototyp
//forward declaration
int CrossSum(int num);

int main() {
    int number = 12340;
    int sum = CrossSum(number);
    std::cout << "Ziffernsumme von " << number << " ist " << sum << std::endl;
    return 0;
}

//berechnet die Quersumme der uebergebenen Zahl
int CrossSum(int num) {
    int remainder = 0;
    int sum = 0;

    if (num< 0 ) {
        num = -num;
    }

    while (num > 0) {
        remainder = num % 10;
        sum += remainder;
        num /= 10;
    }

    return sum;
}