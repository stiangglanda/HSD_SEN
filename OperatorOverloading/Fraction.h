#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>


class Fraction
{
public:


private:


   //groeszter gemeinsamer Teiler
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

#endif //FRACTION_H
