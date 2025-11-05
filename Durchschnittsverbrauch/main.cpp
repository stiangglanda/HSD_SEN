#include <iostream>

using namespace std;

float Durchnscnittsverbrauch(float Kilometer, float Treibstoffmenge) {
    return ((Treibstoffmenge/Kilometer)/1)*100;
}

int main() {
    float Kilometer = 0;
    float Treibstoffmenge = 0;

    std::cout << "Kilometer eingabe:" << std::endl;
    cin >> Kilometer;
    std::cout << "Treibstoffmenge eingabe:" << std::endl;
    cin >> Treibstoffmenge;

    std::cout << "Verbrauch [1/100km]: " << Durchnscnittsverbrauch(Kilometer, Treibstoffmenge) << std::endl;

    return 0;
}