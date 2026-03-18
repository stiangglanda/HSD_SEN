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

    sObj4.Print(cout);
}