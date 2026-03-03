#include <iostream>
using namespace std;

int Quersumme(int zahl) {
    if (zahl == 0) {
        cout << "Abbruchbedingung erreicht" << endl;
        // zahl = 0 => Quersumme = 0
        return 0;
    }
    else {
        cout << "Einwickeln: zahl = " << zahl << endl;
        int result = zahl%10 + Quersumme(zahl/10);
        cout << "Auswickeln: (Zwischen-)Ergebnis: " << result << endl;
        return result;
    }
}

int main() {
    int qs = Quersumme(123);
    cout << "Quersumme: " << qs << endl;


    return 0;
}