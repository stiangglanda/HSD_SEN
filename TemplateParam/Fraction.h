#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

class Fraction
{
public:
   //CTors
   Fraction() = default;
   Fraction(int numerator, int denominator=1);
   Fraction(Fraction const& b);

   //DTor
   ~Fraction();
 
   //operators
   Fraction operator * (Fraction const& f) const;
   Fraction operator + (Fraction const& f) const;
   Fraction& operator = (Fraction const& f);
   bool operator < (Fraction const& f) const;
   bool operator == (Fraction const& f) const;

   //member access
   int GetNumerator() const;
   int GetDenominator() const; 

private:
   int mNumerator = 0;
   int mDenominator = 1;

   //greszter gemeinsamer Teiler
   unsigned int GreatestCommonDivisor(int a, int b) const;

   //interner Rueckgabetyp für Zaehler und Nenner
   struct Reduced
   {
      int num;
      int denom;
   };

   //kuerzen des Bruches
   Reduced Reduce(int numerator, int denominator) const;

};

//Ueberladen des Ausgabeoperators als globale Funktion

std::ostream& operator << (std::ostream& out, Fraction const& f);

#endif //FRACTION_H