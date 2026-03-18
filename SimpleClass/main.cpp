#include <iostream>
#include <fstream>
//#include <vld.h>          //notwendig um den Visual Leak Detector zu verwenden
#include "SimpleClass.h"
using namespace std;

//Fehlerkonstanten
static string const cErrRead = "error reading from file: ";
static string const cFileName = "euro.txt";
static string const cErrOpen = "error open file: ";

int main()
{
    Simple sObj;
    sObj.SetFirstVal(50);
    sObj.SetSecondVal(100);
    cout << sObj.CalcSum() << endl;
    cout << sObj.CalcDiff() << endl;

    Simple sObj2{123, 123};
    sObj2.Print(cout);

    Simple sObj3{sObj};//Kopie von sObj
    Simple sObj4 = sObj2; //das ist auch eine Kopie

    sObj4=sObj3; //das ist eine zuweisung -> kein CopyCTor

    sObj4.PrintFormated(cout);

    //in eine Datei schreiben und lesen
    fstream file{cFileName, ios::trunc | ios::in | ios::out};
    if (file.is_open()) {
        sObj4.PrintFormated(file);
        cout << "write pos: "<< file.tellp() << endl;
        cout << "read pos: "<< file.tellg() << endl;

        file.seekg(0, ios::beg);
        string readData;
        file >> readData;
        cout << endl << "read data: " << readData << endl << endl;

        //Lesezeiger in die Mitte der Datei positionieren
        file.seekg(0, ios::end); // ans Ende setzen
        file.seekg(file.tellg()/2, ios::beg); //in die Mitte positionieren
        cout << "read second half: " << endl << file.rdbuf() << endl << "********finished*******\n\n";

        // auf lesefehler pruefen
        if (!file.eof() && !file.fail()) {
            cerr << cErrRead << cFileName << endl;
        }
        file.close();
    }
    else {
        cerr << cErrOpen << cFileName << endl;
    }
}