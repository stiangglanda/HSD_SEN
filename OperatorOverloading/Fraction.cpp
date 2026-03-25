#include "Fraction.h"
using namespace std;

//Fehlertext
static string const cErrOut = "error in <<-operator()";




//berechne den groeszten gemeinsamen Teiler
unsigned int Fraction::GreatestCommonDivisor(int numerator, int denominator) const
{
   //Euklidischer Algorithmus
   while (denominator != 0) {
      int temp = denominator;
      denominator = numerator % denominator;
      numerator = temp;
   }
   return numerator;

  
}


//Bruch kuerzen
Fraction::Reduced Fraction::Reduce(int numerator, int denominator) const
{
   unsigned int const gcd = GreatestCommonDivisor(numerator, denominator);
   return Reduced{ numerator /= gcd, denominator /= gcd };
}



  