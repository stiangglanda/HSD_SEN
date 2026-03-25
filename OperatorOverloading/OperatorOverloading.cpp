#include "Fraction.h"
#include <iostream>
#include <sstream>
using namespace std;

// Hilfsfunktion fuer den Testausdruck
void PrintTestResult(std::string const& testName, bool const result) {
   cout << testName << ": " << (result ? "OK" : "NOK") << endl;
}

// Test der Fraction-Klasse
void TestFraction() {

   // Standardkonstruktor
   // TO DO
   Fraction f0;
   PrintTestResult("Default CTOR", f0.GetNumerator() == 0 && f0.GetDenominator() == 1);
   PrintTestResult("sizeof-Operator", sizeof(Fraction) == sizeof(f0));

   // Konstruktor mit Parametern
   // TO DO
   Fraction f1{3, 4};
   PrintTestResult("CTor with params 1", f1.GetNumerator() == 3 && f1.GetDenominator() == 4);
   Fraction f2{3};
   PrintTestResult("CTor with params 2", f2.GetNumerator() == 3 && f2.GetDenominator() == 1);

   //Division durch 0
   // TO DO
   Fraction f3{5, 0};
   PrintTestResult("Devision by zero", f3.GetNumerator() == 0 && f3.GetDenominator() == 1);

   //Copy-Konstruktor
   // TO DO
   Fraction f3Copy{f3};
   PrintTestResult("Copy CTor 1", f3Copy.GetNumerator() == f3.GetNumerator() &&
                                          f3Copy.GetDenominator() == f3.GetDenominator());
   // gleich bedeutend mit
   Fraction f3Copy2=f3;
   PrintTestResult("Copy CTor 2", f3Copy2.GetNumerator() == f3.GetNumerator() &&
                                          f3Copy2.GetDenominator() == f3.GetDenominator());

   // Multiplikation
   // TO DO
    Fraction f4{2,5};
    Fraction f5{3,4};
    Fraction f6 = f4 * f5;
    PrintTestResult("Multiplikation 1", f6.GetNumerator() == 3 && f6.GetDenominator() == 10);

    //gleich bedeutend mit
    Fraction f7 = f4.operator*(f5);
    PrintTestResult("Multiplikation 2", f7.GetNumerator() == 3 && f7.GetDenominator() == 10);

    Fraction f8 = f5 * f4;
    PrintTestResult("Multiplikation 3", f8.GetNumerator() == 3 && f8.GetDenominator() == 10);

    // Addition
    // TO DO
    Fraction f9{1,2};
    Fraction f10{1,3};
    Fraction f11 = f9 + f10;
    PrintTestResult("Addition 1", f11.GetNumerator() == 5 && f11.GetDenominator() == 6);
    Fraction f12 = f9.operator+(f10);
    PrintTestResult("Addition 2", f12.GetNumerator() == 5 && f12.GetDenominator() == 6);
    Fraction f13 = f10 + f9;
    PrintTestResult("Addition 3", f13.GetNumerator() == 5 && f13.GetDenominator() == 6);

   // Vergleichsoperatoren
   // TO DO
    Fraction f14{2,3};
    Fraction f15{2,3};
    Fraction f16{1,2};
    PrintTestResult("test1 - operator <", f16 < f14);
    PrintTestResult("test2 - operator <", !(f14 < f16));
    PrintTestResult("test3 - operator <", !(f14 < f15));
    PrintTestResult("test1 - operator ==", f14 == f15);
    PrintTestResult("test2 - operator ==", !(f16 == f15));
    PrintTestResult("test3 - operator ==", !(f14 == f16));

   // Zuweisungsoperator
   // TO DO
    Fraction f17;
    f17=f14;
    PrintTestResult("assign operator 1", f17==f14);

   // Ausgabeoperator
   // TO DO
    cout << f14;
    operator << (cout, f14);
    ostringstream ost1, ost2;
    ost1 << f14;
    Fraction f18{f14};
    ost2 << f18;
    PrintTestResult("operator <<", ost1.str()==ost2.str());

   //Operationen mischen
   // TO DO

   //implizite Typumwandlung
   // TO DO
    PrintTestResult("implicit type conversion", (f0+ 3)== 3);

   //Verhinderung der impliziten Typkonversion durch Angabe von explicit beim CTOR
   // TO DO
}


int main()
{
   cout << "--- Start Test Fraction ---" << endl;
   TestFraction();
   cout << "--- Test finished ---" << endl;
}