#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>


class Fraction
{
public:
   //Default CTor
   Fraction() = default; // keine Impl. in cpp notwendig
   //Ctor mit Parameter
   Fraction(int const numerator, int const denominator = 1);

   //Copy CTor in diesem Fall nicht notwendig, es reicht der Standard-CopyCtor (die Werte werden kopiert)

   //DTor ist in diesem Fall ebenfalls nicht notwendig, da keine Heap-Allokation im CTor statt finden

   //Operator Overloading: *, +, <, ==
   Fraction operator*(Fraction const& f) const;
   Fraction operator+(Fraction const& f) const;
   bool operator<(Fraction const& f) const;
   bool operator==(Fraction const& f) const;

   //Assign Operator ist in diesem Fall nicht notwendig, es Reicht der Default AssignOp aus. Keine Heap Allocation

   //Zugriffsmethoden
   int GetNumerator() const;
   int GetDenominator() const;

private:
   //direkte Member-Initialisierung
   int mNumerator = 0;
   int mDenominator = 1;


   //groeszter gemeinsamer Teiler
   unsigned int GreatestCommonDivisor(int a, int b) const;

   //interner Rueckgabetyp f�r Zaehler und Nenner
   struct Reduced
   {
      int num;
      int denom;
   };

   //kuerzen des Bruches
   Reduced Reduce(int numerator, int denominator) const;

};

// Ueberladen des Ausgabeoperators << als einfache Funktion
std::ostream& operator<<(std::ostream& ost, Fraction const& f);

#endif //FRACTION_H
