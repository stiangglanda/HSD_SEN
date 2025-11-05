#include <iostream>

using namespace std;

// Gibt den Durchnscnittsverbrauch pro 1/100 km zurück bei fehler giebt es -1 zurück
float Durchnscnittsverbrauch(float Kilometer, float Treibstoffmenge) {
    if (Kilometer==0) {
        return -1;
    }

    return ((Treibstoffmenge/Kilometer)/1)*100;
}

int main() {
    float Kilometer = 0;
    float Treibstoffmenge = 0;

    cout << "Kilometer eingabe:" << endl;
    cin >> Kilometer;
    cout << "Treibstoffmenge eingabe:" << endl;
    cin >> Treibstoffmenge;

    cout << "Verbrauch [1/100km]: " << Durchnscnittsverbrauch(Kilometer, Treibstoffmenge) << endl;

    return 0;
}