///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 06. 12. 2025
// Description : Motorstueererungs Kennfelder
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

const int GAS_STEPS = 31;  // 60 / 2 + 1
const int RPM_STEPS = 501; // 5000 / 10 + 1
const int TEMP_STEPS = 91; // (150 + 30) / 2 + 1
const int LOAD_STEPS = 101;// 100 / 1 + 1

struct TInjectionData {
    unsigned char amount; // Einspritzmenge (0-60 mg)
    char timing;          // Einspritzzeitpunkt (-5 bis 15 Grad)
};

TInjectionData Kennfeld[GAS_STEPS][RPM_STEPS][TEMP_STEPS][LOAD_STEPS];

int GetGasIndex(int gas) {
    // Beispiel: 46 Grad / 2 = Index 23
    return gas / 2;
}

int GetRpmIndex(int rpm) {
    // Beispiel: 2200 / 10 = Index 220
    return rpm / 10;
}

int GetTempIndex(int temp) {
    // -30 Grad muss Index 0 sein(Offset)
    // (-20 + 30) / 2 = 10 / 2 = Index 5
    return (temp + 30) / 2;
}

int GetLoadIndex(int load) {
    return load;
}

void SetKennfeldValue(int gas, int rpm, int temp, int load, unsigned char amount, char timing) {
    int iGas = GetGasIndex(gas);
    int iRpm = GetRpmIndex(rpm);
    int iTemp = GetTempIndex(temp);
    int iLoad = GetLoadIndex(load);

    if (iGas >= GAS_STEPS || iRpm >= RPM_STEPS || iTemp >= TEMP_STEPS || iLoad >= LOAD_STEPS) {
        cout << "ERROR index out of bounds" << endl;
        return;
    }

    Kennfeld[iGas][iRpm][iTemp][iLoad].amount = amount;
    Kennfeld[iGas][iRpm][iTemp][iLoad].timing = timing;
}

TInjectionData GetKennfeldValue(int gas, int rpm, int temp, int load) {
    int iGas = GetGasIndex(gas);
    int iRpm = GetRpmIndex(rpm);
    int iTemp = GetTempIndex(temp);
    int iLoad = GetLoadIndex(load);

    return Kennfeld[iGas][iRpm][iTemp][iLoad];
}

int main() {
    cout << "SetKennfeldValue: " << endl;
    SetKennfeldValue(46, 2200, -20, 15, 40, 8);

    cout << "GetKennfeldValue: " << endl;
    TInjectionData result = GetKennfeldValue(46, 2200, -20, 15);

    cout << "Ergebnis:" << endl;
    cout << "Menge: " << (int)result.amount << " mg/Hub" << endl; // Cast auf int für cout Ausgabe nötig bei char
    cout << "Zeit:  " << (int)result.timing << " Grad KW" << endl;

    return 0;
}
