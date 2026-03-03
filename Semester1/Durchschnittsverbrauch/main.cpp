#include <iostream>

using namespace std;

// Gibt den Durchnscnittsverbrauch pro 1/100 km zurück bei fehler giebt es -1 zurück
double Durchnscnittsverbrauch(const double& Kilometer, const double& Treibstoffmenge) {// immer wenn daten größer sind const ref nemen
    if (Kilometer>0&&Treibstoffmenge>0) {
        return -1;
    }

    return Treibstoffmenge * 100 / Kilometer;
}

int main() {
    double Kilometer = 0;
    double Treibstoffmenge = 0;

    while (Kilometer==0) {
        cout << "Kilometer eingabe:" << endl;
        cin >> Kilometer;
    }

    cout << "Treibstoffmenge eingabe:" << endl;
    cin >> Treibstoffmenge;

    cout << "Verbrauch [1/100km]: " << Durchnscnittsverbrauch(Kilometer, Treibstoffmenge) << endl;

    return 0;
}