#include <iostream>
using namespace std;

int Fibunacci(int n) {
    if (n <= 1) { // Abbruchbedingung
        return n;
    }
    else {
        // Einwickeln
        return Fibunacci(n - 2) + Fibunacci(n - 1);
        // Auswickeln
    }
}

int main() {
    int fib = Fibunacci(5);
    cout << "Result: " << fib << endl;
    return 0;
}