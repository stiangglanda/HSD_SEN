#include "Fraction.h"
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

   // Vergleichsoperatoren
   // TO DO

   // Zuweisungsoperator
   // TO DO

   // Ausgabeoperator
   // TO DO

   //Operationen mischen
   // TO DO

   //implizite Typumwandlung
   // TO DO

   //Verhinderung der impliziten Typkonversion durch Angabe von explicit beim CTOR
   // TO DO
}


int main()
{
   cout << "--- Start Test Fraction ---" << endl;
   TestFraction();
   cout << "--- Test finished ---" << endl;
}